#ifndef PARSERFUNCTION_H
#define PARSERFUNCTION_H

#include "AbstractFunction.hpp"
#include <iostream>
#include "../fparser/fparser.hh"
#include <string>

/**
 * \class Parser Function
 * \brief Daughter class of AbstractFunction
 * it implements the methods to get a function from a string written from user
 */

class ParserFunction : public AbstractFunction {
private:
    FunctionParser *fparser; ///< the parser, declared in fparser (external library)
    std::string function; ///< the string (i.e. the function) inserted by user
public:
    ParserFunction();

    ~ParserFunction();

    /**
     * virtual method, overriden from mother class Abstract Function, to let the user set the function to integrate
     * Get a function from a string inserted by the user
     * @param d = dimension in which we are working
     */
    virtual void SetFunction(int d) override;

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x) (1D) \n
     * it evaluates the string (previously inserted by user)
     * @param x
     * @return f(x)
     */
    virtual double getFunctionElement(double x) override;

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x,y) (2D)
     * @param x
     * @param y
     * @return f(x,y)
     */
    virtual double getFunctionElement(double x, double y) override;

};

#endif //PARSERFUNCTION_H
