//
// Created by Leonardo Trentini on 26/11/2022.
//

#ifndef MIDPOINTINTEGRATOR_HPP_
#define MIDPOINTINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

class MidpointIntegrator : public AbstractIntegrator {
public:
    MidpointIntegrator();
    virtual ~MidpointIntegrator();

    virtual double Integrate() override;
};



#endif /* MIDPOINTINTEGRATOR_HPP_ */