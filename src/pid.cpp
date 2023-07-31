#include <algorithm>

#include "pid.hpp"

Pid::Pid(double sampling_time, double kp, double ki, double kd, double kt, 
            double saturation_limit_min, double saturation_limit_max){
    this->sampling_time = sampling_time;
    this->saturation_limit_min = saturation_limit_min;
    this->saturation_limit_max = saturation_limit_max;

    prev_measurement = 0;
    prev_error = 0;
    prev_integral_action = 0;
    prev_derivative_action = 0;

    setGains(kp, ki, kd, kt);
}

void Pid::setGains(double kp, double ki, double kd, double kt){
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->kt = kt;
}

double Pid::getTotalAction(double setpoint, double measurement){
    error = setpoint - measurement;

    integral_action = getIntegralAction(error);
    derivative_action = getDerivativeAction(measurement);

    prev_measurement = measurement;
    prev_error = error;
    prev_integral_action = integral_action;
    prev_derivative_action = derivative_action;

    return checkSaturation(kp*(1 + integral_action + derivative_action));
}

double Pid::getIntegralAction(double error){
    return prev_integral_action + ki*sampling_time/2*(error + prev_error);
}

double Pid::getDerivativeAction(double measurement){
    return (2*kt - sampling_time)/(2*kt + sampling_time)*prev_derivative_action
            - 2*kd/(2*kt + sampling_time)*(measurement - prev_measurement);
}

double Pid::checkSaturation(double action){
    return std::min(std::max(action, saturation_limit_min), saturation_limit_max);
}