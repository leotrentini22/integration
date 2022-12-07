//
// Created by Leonardo Trentini on 26/11/2022.
//

#ifndef MIDPOINTINTEGRATOR_HPP_
#define MIDPOINTINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

/**
 * Daughter class of AbstractIntegrator
 * it implements the midpoint integrator method (see Chapter 3 of Scientific Computing (Quarteroni, Saleri) for a mathematical explanation
 */

class MidpointIntegrator : public AbstractIntegrator {
public:
    MidpointIntegrator();
    virtual ~MidpointIntegrator();

    virtual double Integrate() override;
};



#endif /* MIDPOINTINTEGRATOR_HPP_ */