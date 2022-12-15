#ifndef MIDPOINTINTEGRATOR_HPP_
#define MIDPOINTINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

/**
 * \class MidpointIntegrator
 * \brief Daughter class of AbstractIntegrator\n
 * it implements the midpoint integrator method
 */

class MidpointIntegrator : public AbstractIntegrator {
public:
    MidpointIntegrator();
    virtual ~MidpointIntegrator();

    /**
     * virtual method, overriden from mother class Abstract Integrator\n
     * Implements Midpoint integration in 1D and 2D
     * \return result
     */
    virtual double Integrate() override;
};



#endif /* MIDPOINTINTEGRATOR_HPP_ */