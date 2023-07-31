#ifndef PID_HPP
#define PID_HPP

class Pid{
    public:
        Pid(double, double, double, double, double, double, double, double = 0.1);

        void setGains(double, double, double, double);

        double getTotalAction(double, double);
        
        double kp;
        double ki;
        double kd;
        double kt;

    private:
        double getIntegralAction(double);
        double getDerivativeAction(double);
        double checkSaturation(double, double, double);
        
        double measurement;
        double error;
        double integral_action;
        double derivative_action;
        double total_action;

        double prev_measurement;
        double prev_error;
        double prev_integral_action;
        double prev_derivative_action;

        double limit_min;
        double limit_max;
        double integral_limit_min;
        double integral_limit_max;

        double sampling_time;
};

#endif
