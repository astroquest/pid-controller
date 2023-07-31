#include "model.hpp"

Model::Model(double x0){
    initialize(x0);
}

void Model::initialize(double x0){
    x = x0;
}

void Model::propagateState(double u){
    x = 0.9*x + u;
}