#ifndef MIDPOINTINTEGRATION_HPP_
#define MIDPOINTINTEGRATION_HPP_

#include <ostream>
#include "AbstractIntegration.hpp"

class MidpointIntegration : public AbstractIntegration {
public:
    MidpointIntegration();
    virtual ~MidpointIntegration();

    virtual double Integrate() override;
};



#endif /* MIDPOINTINTEGRATION_HPP_ */