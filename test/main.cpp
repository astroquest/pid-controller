#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

#include "../src/pid.hpp"
#include "pid_settings.hpp"
#include "simulation/model.hpp"

void dumpSim(std::string file_name, std::vector<double> time, std::vector<double> input_vec, std::vector<double> output_vec){
    std::ofstream dump;
    dump.open(file_name);
    dump << "t (s)" << "," << "u" << "," << "y" << std::endl;

    for(int i = 0; i < time.size(); i++){
        dump << std::setprecision(15) << time[i] << "," << input_vec[i] << "," << output_vec[i] << std::endl;
    }

    dump.close();
}

int main(){
    Model model(0);
    Pid pid(sampling_time, kp, kd, ki, kt, saturation_limit_min, saturation_limit_max);
    
    double reference = 1;
    double measurement;
    double input = 0;

    std::vector<double> time;
    std::vector<double> input_vec;
    std::vector<double> output_vec;

    for(int i = 0; i < 1000; i++){
        measurement = model.x;

        time.push_back(i);
        input_vec.push_back(input);
        output_vec.push_back(measurement);

        input = pid.getTotalAction(reference, measurement);
        
        model.propagateState(input);
    }

    dumpSim("../test/data/sim_results.txt", time, input_vec, output_vec);
    
    return 0;
}