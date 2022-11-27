//
// Created by Leonardo Trentini on 26/11/2022.
//

//methods for Midpoint Integrator - 1D and 2D

#include "MidpointIntegrator.hpp"
#include <cmath>

// constructor and destructor

MidpointIntegrator::MidpointIntegrator() {}

MidpointIntegrator::~MidpointIntegrator() {}


// integration

double MidpointIntegrator::Integrate() {
    double x_first=GetFirstExtreme();
    double h=GetStepSize();
    double x_eval=(2*x_first+h)/2;
    int N=GetNumberofPartitions();
    int M=GetNumberofPartitionsY();
    double sum=0;

    //implementation 1D (M = partitions for y == 0)
    if(M==0) {
        for (int i = 0; i < N; i++) {
            sum += Function(x_eval);
            x_eval = x_eval + h;
        }
        result=sum*h;
        return result;
    }

    // implementation 2D
    double y_first=GetFirstExtremeY();
    double k=GetStepSizeY();
    double y_eval=(2*y_first+k)/2;
    for (int i = 0; i < N; i++) {
        y_eval=(2*y_first+k)/2;
        for (int j = 0; j < M; j++){
            sum += Function(x_eval,y_eval);
            y_eval = y_eval + k;
        }
        x_eval = x_eval + h;
    }

    result = sum * h * k;
    return result;


}


