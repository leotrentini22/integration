
#ifndef CODEDFUNCTION_HPP_
#define CODEDFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "CodedFunction.hpp"

class CodedFunction : public AbstractFunction{
private:
    double f_to_integrate(double x,double y) { return x*y;}
    double f_to_integrate(double x) { return x;}

public:
    // Constructor:
    CodedFunction();

    // Destructor:
    ~CodedFunction();

    //Methods:

    virtual void SetFunction() override;

    virtual double getFunctionElement(double x) override;
    virtual double getFunctionElement(double x, double y) override;

};

#endif /* CODEDFUNCTION_HPP_ */