//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "MidpointIntegration.hpp"
#include <cmath>

MidpointIntegration::MidpointIntegration() {}

MidpointIntegration::~MidpointIntegration() {}

double MidpointIntegration::Integrate() {
    double x0=GetFirstExtreme();
    double h=GetStepSize();
    double x_eval=(2*x0+h)/2;
    int N=GetNumberofPartitions();
    double sum=0;
    for (int i=0;i<N-1;i++){
        sum+= Function(x_eval);
        x_eval=x_eval+h;
    }

    return sum*h;

}


