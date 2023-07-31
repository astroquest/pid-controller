#ifndef MODEL_HPP
#define MODEL_HPP

struct Model{
        Model(double);

        void initialize(double);

        void propagateState(double);

        double x;
};

#endif