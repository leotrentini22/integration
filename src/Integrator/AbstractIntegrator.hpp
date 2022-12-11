//
// Created by Leonardo Trentini on 26/11/2022.
//

#ifndef ABSTRACTINTEGRATOR_HPP_
#define ABSTRACTINTEGRATOR_HPP_

#include <ostream>
#include "../Function/AbstractFunction.hpp"

/**
 * Abstract class of integrators, with 3 derived classes
 * MidpointIntegrator, TrapezoidalIntegrator, SimpsonIntegrator
 * Stores the extremes of the domain, the number of partitions and useful methods for the integration
 */

class AbstractIntegrator {
private:
    // extremes in x dimension
    double x0;
    double xN;

    //extremes in y dimension
    double y0;
    double yM;

    //number of partitions
    int N_partitions; // on x dimension
    int M_partitions; // on y dimension

    //function to integrate
    AbstractFunction *f;

protected:
    double result;
public:
    // Constructor and destructor
    AbstractIntegrator();

    virtual ~AbstractIntegrator();

    // Other public methods - 1 D
    void SetNumberOfPartitions(const int N);
    void SetExtremes(const double x_a, const double x_b);
    void SetFunction(AbstractFunction *function);

    double Function(double x) const;

    //Other public methods - 2 D
    void SetNumberOfPartitions(const int N, const int M);
    void SetExtremes(const double x_a, const double x_b, const double x_c, const double x_d);
    //void SetFunction(double (*f)(double x, double y));

    double Function(double x, double y) const;

    // Pure virtual method "Integrate"

    virtual double Integrate() = 0;

    // Get methods

    double GetResult() const { return result; } // to use only after "Integrate"

       // if 1 D

    double GetFinalExtreme() const { return xN; }

    double GetFirstExtreme() const { return x0; }

    double GetStepSize() const { return (xN-x0)/(double)(N_partitions); }

    int GetNumberofPartitions() const {return N_partitions;}

       // if 2D

    double GetFinalExtremeX() const { return xN; }

    double GetFirstExtremeX() const { return x0; }

    double GetFinalExtremeY() const { return yM; }

    double GetFirstExtremeY() const { return y0; }

    double GetStepSizeX() const { return (xN-x0)/(double)(N_partitions); }

    double GetStepSizeY() const { return (yM-y0)/(double)(M_partitions); }

    int GetNumberofPartitionsX() const {return N_partitions;}

    int GetNumberofPartitionsY() const {return M_partitions;}


};

#endif /* ABSTRACTINTEGRATOR_HPP_ */
