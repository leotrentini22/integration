#ifndef TRAPEZOIDALINTEGRATOR_HPP_
#define TRAPEZOIDALINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

/**
 * Daughter class of AbstractIntegrator
 * it implements the trapezoidal integrator method (see Chapter 3 of Scientific Computing (Quarteroni, Saleri) for a mathematical explanation
 */

class TrapezoidalIntegrator : public AbstractIntegrator {
public:
    TrapezoidalIntegrator();
    virtual ~TrapezoidalIntegrator();

    virtual double Integrate() override;
};



#endif /* TRAPEZOIDALINTEGRATOR_HPP_ */