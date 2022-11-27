//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "SimpsonIntegrator.hpp"
#include <cmath>

SimpsonIntegrator::SimpsonIntegrator() {}

SimpsonIntegrator::~SimpsonIntegrator() {}



double SimpsonIntegrator::Integrate() {
    double x0=GetFirstExtreme();
    double h=GetStepSize();
    double xold=x0;
    double xnew=x0+h;
    int N=GetNumberofPartitionsX();
    //int M=GetNumberofPartitionsY();
    double sum = 0;
    //if(M==0) {
        for (int i = 0; i < N; i++) {
            sum += Function(xold) + Function(xnew) + 4 * Function((xold + xnew) / 2);
            xold = xnew;
            xnew = xnew + h;
        }

        result = sum * h / 6;
        return result;
    //}



}


