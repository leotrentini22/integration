#ifndef CODEDFUNCTION_HPP_
#define CODEDFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "AbstractFunction.hpp"

/**
 * \class Coded Function
 * \brief Daughter class of AbstractFunction
 * it implements the methods to use a function directly coded by the user (need to recompile everytime)
 */

class CodedFunction : public AbstractFunction{

public:
    // Constructor:
    CodedFunction();

    // Destructor:
    ~CodedFunction();

    //Methods:
    virtual void SetFunction(int d) override{}; ///< not used for Coded Function class

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x) (1D) \n
     * f(x) is directly coded here!
     * @param x
     * @return f(x)
     */
    virtual double getFunctionElement(double x) override;

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x,y) (2D)
     * f(x,y) is directly coded here!
     * @param x
     * @param y
     * @return f(x,y)
     */
    virtual double getFunctionElement(double x, double y) override;

};

#endif /* CODEDFUNCTION_HPP_ */