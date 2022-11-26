#ifndef MIDPOINTINTEGRATION_HPP_
#define MIDPOINTINTEGRATION_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

class MidpointIntegrator : public AbstractIntegrator {
public:
    MidpointIntegrator();
    virtual ~MidpointIntegrator();

    virtual double Integrate() override;
};



#endif /* MIDPOINTINTEGRATION_HPP_ */