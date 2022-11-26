//
// Created by Leonardo Trentini on 26/11/2022.
//

#ifndef TRAPEZOIDALINTEGRATOR_HPP_
#define TRAPEZOIDALINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

class TrapezoidalIntegrator : public AbstractIntegrator {
public:
    TrapezoidalIntegrator();
    virtual ~TrapezoidalIntegrator();

    virtual double Integrate() override;
};



#endif /* TRAPEZOIDALINTEGRATOR_HPP_ */