//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "TrapezoidalIntegrator.hpp"
#include <cmath>

TrapezoidalIntegrator::TrapezoidalIntegrator() {}

TrapezoidalIntegrator::~TrapezoidalIntegrator() {}

double TrapezoidalIntegrator::Integrate() {
    double x0=GetFirstExtreme();
    double h=GetStepSize();
    double xold=x0;
    double xnew=x0+h;
    int N=GetNumberofPartitions();
    double sum=0;
    for (int i=0;i<N;i++){
        sum+= Function(xold)+Function(xnew);
        xold=xnew;
        xnew=xnew+h;
    }

    return sum*h/2;

}

