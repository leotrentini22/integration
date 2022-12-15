#ifndef ABSTRACTFUNCTION_HPP_
#define ABSTRACTFUNCTION_HPP_

#include <ostream>
#include <vector>

/**
 * \class AbstractFunction
 * \brief Abstract class of function, with 3 daughter classes (ways of getting function from user)\n
 * Only pure virtual methods
 */

class AbstractFunction{
public:
    // Constructor:
    AbstractFunction();

    // Destructor:
    virtual ~AbstractFunction();

    //Methods:
    /**
     * Pure virtual method to let the user set the function to integrate
     * @param d = dimension in which we are working
     */
    virtual void SetFunction(int d)=0;

    /**
     * Pure virtual method to evaluate the function f(x) (1 dimension)
     * @param x = point of evaluation
     * @return f(x)
     */
    virtual double getFunctionElement(double x)=0;

    /**
     * Pure virtual method to evaluate the function f(x,y) (2 dimension)
     * @param x = point of evaluation in x dimension
     * @param y = point of evaluation in y dimension
     * @return f(x,y)
     */
    virtual double getFunctionElement(double x, double y)=0;


};

#endif /* ABSTRACTFUNCTION_HPP_ */