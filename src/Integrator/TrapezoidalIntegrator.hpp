#ifndef TRAPEZOIDALINTEGRATOR_HPP_
#define TRAPEZOIDALINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

/**
 * \class TrapezoidalIntegrator
 * \brief Daughter class of AbstractIntegrator\n
 * it implements the trapezoidal integrator method
 */

class TrapezoidalIntegrator : public AbstractIntegrator {
public:
    TrapezoidalIntegrator();
    virtual ~TrapezoidalIntegrator();

    /**
     * virtual method, overriden from mother class AbstractIntegrator\n
     * Implements trapezoidal integration in 1D and 2D
     * \return result
     */
    virtual double Integrate() override;
};



#endif /* TRAPEZOIDALINTEGRATOR_HPP_ */