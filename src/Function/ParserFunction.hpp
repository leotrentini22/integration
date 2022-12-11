//
// Created by Odile on 02.12.2022.
//

#ifndef PARSERFUNCTION_H
#define PARSERFUNCTION_H

#include "AbstractFunction.hpp"
#include <iostream>
#include "../fparser/fparser.hh"
#include <string>

/**
 * Daughter class of AbstractFunction
 * it implements the methods to get a function from a string written from user
 */

class ParserFunction : public AbstractFunction {
private:
    FunctionParser *fparser;
    std::string function;
public:
    ParserFunction();

    ~ParserFunction();

    virtual void SetFunction(int d) override;
    virtual double getFunctionElement(double x) override;
    virtual double getFunctionElement(double x, double y) override;

};

#endif //PARSERFUNCTION_H
