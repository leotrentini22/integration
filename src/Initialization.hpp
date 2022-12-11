//
// Created by Odile on 03.12.2022.
//

#ifndef INTEGRATION_INITIALIZATION_H
#define INTEGRATION_INITIALIZATION_H

#include <iostream>

/**
 * Class made in order to make the main more readable
 */

class Initialization{

private:

    // Bound of the domain
    double initialX, finalX, initialY, finalY;

    //N and M are the number of partition for x and y
    int N,M;

    //d: dimension of the function to integrate
    int d;
    //m: method to integrate (1 Midpoint, 2: Trapezoidal, 3: Cavalieri-Simpson)
    int m;
    //result: result of the integration
    double result;

    //pointer to the function to integrate:
    AbstractFunction *pfunction;

public:
    //Constructor:
    Initialization();

    //Destructor:
    ~Initialization();

    //Methods to set members:
    void SetDimension();
    void SetParameters();
    void ChooseMethod();
    void SetFunctionToIntegrate();

    //Method to get members:
    double GetInitialX() {return initialX;};
    double GetFinalX() {return finalX;};
    double GetInitialY() {return initialY;};
    double GetFinalY() {return finalY;};
    int GetN(){return N;};
    int GetM(){return M;};
    int GetDimension(){return d;};
    int GetMethod(){return m;};
    double GetResult(){return result;};

    double CalculateIntegral();

    void PrintResult() const;


    // Write down result to file

    void WriteResultToFile(std::ostream &stream) const {stream << result;};

};

#endif //INTEGRATION_INITIALIZATION_H
