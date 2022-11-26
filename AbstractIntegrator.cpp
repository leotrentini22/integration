//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "AbstractIntegrator.hpp"

AbstractIntegrator::AbstractIntegrator()
    : x0(), xN(), N_partitions(), function(0){}

AbstractIntegrator::~AbstractIntegrator() {}

void AbstractIntegrator::SetExtremes(const double a, const double b) {x0=a;xN=b;}

void AbstractIntegrator::SetNumberOfPartitions(const int N) {N_partitions=N;}

void AbstractIntegrator::SetFunction(double (*f)(double)) {function=f;}

double AbstractIntegrator::Function(double x) const{return function(x);}
