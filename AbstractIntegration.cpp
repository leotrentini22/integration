//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "AbstractIntegration.hpp"

AbstractIntegration::AbstractIntegration()
    : x0(), xN(), N_partitions(), function(0){}

AbstractIntegration::~AbstractIntegration() {}

void AbstractIntegration::SetExtremes(const double a, const double b) {x0=a;xN=b;}

void AbstractIntegration::SetNumberOfPartitions(const int N) {N_partitions=N;}

void AbstractIntegration::SetFunction(double (*f)(double)) {function=f;}

double AbstractIntegration::Function(double x) const{return function(x);}
