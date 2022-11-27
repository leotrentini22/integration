//
// Created by Leonardo Trentini on 26/11/2022.
//

#ifndef SIMPSONINTEGRATOR_HPP_
#define SIMPSONINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

class SimpsonIntegrator : public AbstractIntegrator {
public:
    SimpsonIntegrator();
    virtual ~SimpsonIntegrator();

    virtual double Integrate() override;
    double getCoeffS(int i, int j, int Nx, int My);
};



#endif /* SIMPSONINTEGRATOR_HPP_ */