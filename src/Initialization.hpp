#ifndef INTEGRATION_INITIALIZATION_H
#define INTEGRATION_INITIALIZATION_H

#include <iostream>

/**
 * \class Initialization
 * \brief Class made in order to make the main more readable
 * It contains all the methods to print instructions to user, get inputs, run the calculation and print the result (either to the screen or into a file)
 */

class Initialization{

private:

    double initialX, finalX, initialY, finalY; ///< Bound of the domain

    int N,M; ///< number of partitions for x (N) and y(M)

    int d; ///< dimension of the function to integrate

    int m; ///< method to integrate (1 Midpoint, 2: Trapezoidal, 3: Cavalieri-Simpson)

    double result; ///<result of the integration

    AbstractFunction *pfunction; ///< function to integrate

public:
    ///Constructor:
    Initialization();

    ///Destructor:
    ~Initialization();

    //Methods to set members:
    void SetDimension(); ///<Sets the dimension (either 1 or 2)
    void SetParameters(); ///<Sets the domain extremes ((a,b) in 1 dimension, [(a,b)x(c,d)] in 2 dimensions) and the number(s) of partitions
    void ChooseMethod(); ///<Chooses the numerical algorithm that will be used to calculate the integral::m

    /** Method that states how the function to integrate is taken from user and then sets the function to integrate \n
     * Three different manners to take function from user:\n
     * - ParserFunction = function from string \n
     * - ForderFunction = function assembled step by step from user \n
     * - CodedFunction = function directly coded (need to be recompiled everytime) \n
     * This choice is not designed to be done by the user through inputs on the screen. If you want to change the behaviour, you should change this method and recompile
     */
    void SetFunctionToIntegrate();

    //Methods to get private members:
    double GetInitialX() const {return initialX;};
    double GetFinalX() const {return finalX;};
    double GetInitialY() const {return initialY;};
    double GetFinalY() const {return finalY;};
    int GetN() const {return N;}; ///<Gets the number of partitions in x dimension, \return N
    int GetM() const {return M;}; ///<Gets the number of partitions in y dimension, \return M
    int GetDimension() const {return d;}; ///<Gets the dimension (1 or 2), \return d
    int GetMethod() const {return m;}; ///<Gets the method, \return m (1 = Midpoint, 2 = Trapezoidal, 3 = Simpson)
    double GetResult() const {return result;}; ///<\return result

    /**
     * Method that initialize the calculation with the chosen method and given parameters
     * @return result
     */
    double CalculateIntegral();

    void PrintResult() const; ///< method that prints result to the screen


    /**
     * Method to write down the result to a file
     * @param stream (has to be an open file)
     */
    void WriteResultToFile(std::ostream &stream) const {stream << result;};

};

#endif //INTEGRATION_INITIALIZATION_H
