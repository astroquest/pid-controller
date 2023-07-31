#ifndef PID_SETTINGS_HPP
#define PID_SETTINGS_HPP

double sampling_time = 1;

double kp = 0.1;
double ki = 0.01;
double kd = 0.01;
double kt = 0.001;

double limit_min = -0.105;
double limit_max = 0.105;

#endif