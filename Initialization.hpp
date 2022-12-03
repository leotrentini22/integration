//
// Created by Odile on 03.12.2022.
//

#ifndef INTEGRATION_INITIALIZATION_H
#define INTEGRATION_INITIALIZATION_H

#include <iostream>

class Initialization{

private:

    // Bound of the domain
    double initialX, finalX, initialY, finalY;

    //N and M are the number of partition for x and y
    int N,M;

    //d: dimension of the function to integrate
    //m: method to intgrate (1 Midpoint, 2: Trapezoidal, 3: Cavalieri-Simpson)
    int d,m;
    double result;
    AbstractFunction *pfunction;

public:
    //Constructor:
    Initialization();

    //Destructor:
    ~Initialization();

    //Method:
    void SetDimension();
    void SetParameters();
    void ChooseMethod();
    void SetFunctionToIntegrate();
    double CalculateIntegral();
    void PrintResult() const;

    // Write down result to file

    void WriteResultToFile(std::ostream &stream) const {stream << result;};

};

#endif //INTEGRATION_INITIALIZATION_H
