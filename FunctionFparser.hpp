//
// Created by Odile on 02.12.2022.
//

#ifndef INTEGRATION_FUNCTIONFPARSER_H
#define INTEGRATION_FUNCTIONFPARSER_H

#include "AbstractFunction.hpp"
#include <iostream>

class FunctionFparser : public AbstractFunction {
public:
    FunctionFparser();

    ~FunctionFparser();

    virtual double SetFunction() override;

};

#endif //INTEGRATION_FUNCTIONFPARSER_H
