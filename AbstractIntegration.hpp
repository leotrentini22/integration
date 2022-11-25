/*
 * AbstractIntegration.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: Leonardo Trentini
 */

// I think we might use the structure we used in exercise for ODEs:
// - An abstract class, called abstract integration
// - Three derived classes for Midpoint, Trapezoidal, Cavalieri-Simpson

//initializated, not finished

#ifndef ABSTRACTINTEGRATION_HPP_
#define ABSTRACTINTEGRATION_HPP_

#include <ostream>

class AbstractIntegration {
public:
    // Constructor and destructor
    AbstractIntegration();

    virtual ~AbstractIntegration();

};

#endif /* ABSTRACTINTEGRATION_HPP_ */
