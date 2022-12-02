//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "AbstractIntegrator.hpp"

AbstractIntegrator::AbstractIntegrator()
    : x0(), xN(), N_partitions(), function1D(0), result(), function2D(0) {}

AbstractIntegrator::~AbstractIntegrator() {}

void AbstractIntegrator::SetExtremes(const double x_a, const double x_b) {x0=x_a;xN=x_b;y0=0;yM=0;}

void AbstractIntegrator::SetNumberOfPartitions(const int N) {N_partitions=N; M_partitions=0;}

void AbstractIntegrator::SetFunction(double (*f)(double)) {
    //function1D=f;
    function2D=0;
}
double AbstractIntegrator::Function(double x) const{return f.getFunctionElement(x);}


// 2 D

void AbstractIntegrator::SetExtremes(const double x_a, const double x_b, const double y_a, const double y_b) {x0=x_a;xN=x_b;y0=y_a;yM=y_b;}

void AbstractIntegrator::SetNumberOfPartitions(const int N, const int M) {N_partitions=N; M_partitions=M;}

void AbstractIntegrator::SetFunction(double (*f)(double,double)) {function2D=f;function1D=0;}

double AbstractIntegrator::Function(double x,double y) const{return function2D(x,y);}
