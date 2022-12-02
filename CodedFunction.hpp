
#ifndef CODEDFUNCTION_HPP_
#define CODEDFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "AbstractFunction.hpp"

class CodedFunction : public AbstractFunction{

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