#ifndef CODEDFUNCTION_HPP_
#define CODEDFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "AbstractFunction.hpp"

/**
 * \class CodedFunction
 * \brief Daughter class of AbstractFunction \n
 * it implements the methods to use a function directly coded by the user (need to recompile everytime)
 */

class CodedFunction : public AbstractFunction{

public:
    // Constructor:
    CodedFunction();

    // Destructor:
    ~CodedFunction();

    //Methods:
    /**
     * not used for Coded Function class
     * @param d = dimension
     */
    virtual void SetFunction(int d) override{};

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x) (1D) \n
     * f(x) is directly coded here!
     * @param x = point of evaluation
     * @return f(x)
     */
    virtual double getFunctionElement(double x) override;

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x,y) (2D)
     * f(x,y) is directly coded here!
     * @param x = point of evaluation in x dimension
     * @param y = point of evaluation in y dimension
     * @return f(x,y)
     */
    virtual double getFunctionElement(double x, double y) override;

};

#endif /* CODEDFUNCTION_HPP_ */