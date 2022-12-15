#ifndef SIMPSONINTEGRATOR_HPP_
#define SIMPSONINTEGRATOR_HPP_

#include <ostream>
#include "AbstractIntegrator.hpp"

/**
 * \class SimpsonIntegrator
 * \brief Daughter class of AbstractIntegrator\n
 * it implements the Simpson integrator method
 */

class SimpsonIntegrator : public AbstractIntegrator {
public:
    SimpsonIntegrator();
    virtual ~SimpsonIntegrator();

    /**
     * virtual method, overriden from mother class AbstractIntegrator\n
     * Implements Simpson integration in 1D and 2D
     * \return result
     */
    virtual double Integrate() override;

    /**
     * Method that gets the coefficient for simpson integration in 2D
     * @param i = (i-th-1) element of the grid in x dimension
     * @param j = (j-th-1) element of the grid in y dimension
     * @param Nx = number of partitions in x dimension
     * @param My = number of partitions in y dimension
     * @return the coefficients for Simpson integration in 2D
     */
    double getCoeffS(int i, int j, int Nx, int My);
};



#endif /* SIMPSONINTEGRATOR_HPP_ */