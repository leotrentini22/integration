#ifndef ABSTRACTINTEGRATOR_HPP_
#define ABSTRACTINTEGRATOR_HPP_

#include <ostream>
#include "../Function/AbstractFunction.hpp"

/**
 * \class AbstractIntegrator
 * \brief Abstract class of integrators, with 3 daughter classes \n
 * The 3 daughter classes are MidpointIntegrator, TrapezoidalIntegrator, SimpsonIntegrator\n
 * It stores the extremes of the domain, the number of partitions and useful methods for the integration
 */

class AbstractIntegrator {
private:

    double x0; ///<first extreme in x dimension
    double xN; ///<last extreme in x dimension

    double y0; ///<first extreme in y dimension
    double yM; ///<last extreme in x dimension

    int N_partitions; ///< number of partitions in x dimension
    int M_partitions; ///< number of partitions in y dimension

    AbstractFunction *f; ///<function to integrate

protected:
    double result;
public:
    // Constructor and destructor
    AbstractIntegrator(); ///< Constructor

    virtual ~AbstractIntegrator(); ///<Destructor

    // Other public methods - 1 D
    /**
     * Set the number of partitions in 1D
     * @param N = number of partitions
     */
    void SetNumberOfPartitions(const int N);

    /**
     * Set extremes of the domain in 1D
     * @param x_a = first extreme
     * @param x_b = last extreme
     */
    void SetExtremes(const double x_a, const double x_b);

    /**
     * Set the function to integrate
     * @param function = pointer of Abstract Function, got from the user in different manners (see ::AbstractFunction)
     */
    void SetFunction(AbstractFunction *function);

    /**
     * Evaluation of our function in 1D
     * @param x = point of evaluation
     * @return f(x)
     */
    double Function(double x) const;

    //Other public methods - 2 D
    /**
     * Set the number of partitions in 2D
     * @param N = number of partitions in x dimension
     * @param M = number of partitions in y dimension
     */
    void SetNumberOfPartitions(const int N, const int M);

    /**
     * Set extremes of the domain in 2D
     * @param x_a = first extreme in x dimension
     * @param x_b = last extreme in x dimension
     * @param x_c = first extreme in y dimension
     * @param x_d = last extreme in y dimension
     */
    void SetExtremes(const double x_a, const double x_b, const double x_c, const double x_d);

    /**
     * Evaluation of our function in 2D
     * @param x = point of evaluation in x dimension
     * @param y = point of evaluation in y dimension
     * @return f(x,y)
     */
    double Function(double x, double y) const;

    // Pure virtual method "Integrate"

    /**
     * Pure virtual method to integrate (using the chosen numerical algorithm)
     * @return the result of integration
     */
    virtual double Integrate() = 0;

    // Get methods

    double GetResult() const { return result; } //to use only after integrate

       // if 1 D

    double GetFinalExtreme() const { return xN; }

    double GetFirstExtreme() const { return x0; }

    double GetStepSize() const { return (xN-x0)/(double)(N_partitions); } ///< returns the step size if 1D (i.e., returns step size in x dimension)

    int GetNumberofPartitions() const {return N_partitions;}

       // if 2D

    double GetFinalExtremeX() const { return xN; }

    double GetFirstExtremeX() const { return x0; }

    double GetFinalExtremeY() const { return yM; }

    double GetFirstExtremeY() const { return y0; }

    double GetStepSizeX() const { return (xN-x0)/(double)(N_partitions); } ///<returns the step size in x dimension

    double GetStepSizeY() const { return (yM-y0)/(double)(M_partitions); } ///<returns the step size in y dimension

    int GetNumberofPartitionsX() const {return N_partitions;}

    int GetNumberofPartitionsY() const {return M_partitions;}


};

#endif /* ABSTRACTINTEGRATOR_HPP_ */
