#ifndef PID_HPP
#define PID_HPP

class Pid{
    public:
        Pid(double, double, double, double, double, double, double);

        void setGains(double, double, double, double);

        double getTotalAction(double, double);
        
        double kp;
        double ki;
        double kd;
        double kt;

    private:
        double getIntegralAction(double);
        double getDerivativeAction(double);
        double checkSaturation(double);
        
        double measurement;
        double error;
        double integral_action;
        double derivative_action;
        double total_action;

        double prev_measurement;
        double prev_error;
        double prev_integral_action;
        double prev_derivative_action;

        double saturation_limit_min;
        double saturation_limit_max;

        double sampling_time;
};

#endif
