/*
 * AbstractIntegration.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: Leonardo Trentini
 */

// I think we might use the structure we used in exercise for ODEs:
// - An abstract class, called abstract integration
// - Three derived classes for Midpoint, Trapezoidal, Cavalieri-Simpson

//initialized, not finished

#ifndef ABSTRACTINTEGRATION_HPP_
#define ABSTRACTINTEGRATION_HPP_

#include <ostream>

class AbstractIntegration {
private:
    double x0;
    double xN;
    int N_partitions;
    double (*function)(double x);
public:
    // Constructor and destructor
    AbstractIntegration();

    virtual ~AbstractIntegration();

    // Other public methods
    void SetNumberOfPartitions(const int N);
    void SetExtremes(const double a, const double b);
    void SetFunction(double (*f)(double x));

    double Function(double x) const;
    virtual double Integrate() = 0;

    // Get methods
    double GetFinalExtreme() const { return x0; }

    double GetFirstExtreme() const { return xN; }

    double GetStepSize() const { return (xN-x0)/(double)(N_partitions); }

    int GetNumberofPartitions() const {return N_partitions;}

};

#endif /* ABSTRACTINTEGRATION_HPP_ */
