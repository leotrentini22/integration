//
// Created by Odile on 02.12.2022.
//

#ifndef PARSERFUNCTION_H
#define PARSERFUNCTION_H

#include "AbstractFunction.hpp"
#include <iostream>
#include "fpaser/fparser.hh"
#include <string>

class ParserFunction : public AbstractFunction {
private:
    FunctionParser *fparser;
    std::string function;
public:
    ParserFunction();

    ~ParserFunction();

    virtual void SetFunction() override;
    virtual double getFunctionElement(double x) override;
    virtual double getFunctionElement(double x, double y) override;

};

#endif //PARSERFUNCTION_H
