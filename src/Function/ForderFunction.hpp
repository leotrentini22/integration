//I defined a class Function as suggested from the TA, not sure if it is the best way

#ifndef FORDERFUNCTION_HPP_
#define FORDERFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "AbstractFunction.hpp"

/**
 * \class ForderFunction
 * \brief Daughter class of AbstractFunction \n
 * it implements the methods to get a function from built step by step iteratively by the user
 */

class ForderFunction : public AbstractFunction{
protected:
    std::vector<int> forder; ///< vector that stores the sequence of operations chosen by user
    std::vector<int> corder; ///< vector that stores the sequence of constants (multiplied or added) chosen by user
public:
    // Constructor:
    ForderFunction();

    // Destructor:
    ~ForderFunction();

    //Methods:

    /**
     * virtual method, overriden from mother class Abstract Function, to let the user set the function to integrate
     * Compose a function iteratively from user choices
     * @param d = dimension in which we are working
     */
    virtual void SetFunction(int d) override;

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x) (1D) \n
     * @param x = point of evaluation
     * @return f(x)
     */
    virtual double getFunctionElement(double x) override;

    /**
     * virtual method, overriden from mother class Abstract Function, to evaluate f(x,y) (2D)
     * @param x = point of evaluation in x dimension
     * @param y = point of evaluation in y dimension
     * @return f(x,y)
     */
    virtual double getFunctionElement(double x, double y) override;

};

#endif /* FORDERFUNCTION_HPP_ */