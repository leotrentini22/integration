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
public:
    //Constructor:
    Initialization();

    //Destructor:
    ~Initialization();

    //Method:
    void SetDimension();
    void SetDomainExtremes();
    void ChooseMethod();
    double CalculateIntegral();
    void PrintResult();

    // Write down result to file

    void WriteResult(std::ostream &stream) const {stream << result;};

};

#endif //INTEGRATION_INITIALIZATION_H
