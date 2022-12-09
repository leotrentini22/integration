//
// Created by Leonardo Trentini on 26/11/2022.
//

//methods for Abstract Integrator class - 1D and 2D

#include "AbstractIntegrator.hpp"

AbstractIntegrator::AbstractIntegrator()
    : x0(), xN(), N_partitions(), result(), f() {

}

AbstractIntegrator::~AbstractIntegrator() {}

//1D

void AbstractIntegrator::SetExtremes(const double x_a, const double x_b) {x0=x_a;xN=x_b;y0=0;yM=0;}

void AbstractIntegrator::SetNumberOfPartitions(const int N) {N_partitions=N; M_partitions=0;}

//evaluate the function (1D)
double AbstractIntegrator::Function(double x) const{return f->getFunctionElement(x);}

//Set the function (works for both 1D and 2D)
void AbstractIntegrator::SetFunction(AbstractFunction *function) {
    f=function;
}


//2D
void AbstractIntegrator::SetExtremes(const double x_a, const double x_b, const double y_a, const double y_b) {x0=x_a;xN=x_b;y0=y_a;yM=y_b;}

void AbstractIntegrator::SetNumberOfPartitions(const int N, const int M) {N_partitions=N; M_partitions=M;}

double AbstractIntegrator::Function(double x, double y) const{return f->getFunctionElement(x, y);}


