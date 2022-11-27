//
// Created by Leonardo Trentini on 26/11/2022.
//

#include "MidpointIntegrator.hpp"
#include <cmath>

MidpointIntegrator::MidpointIntegrator() {}

MidpointIntegrator::~MidpointIntegrator() {}

double MidpointIntegrator::Integrate() {
    double x_first=GetFirstExtreme();
    double h=GetStepSize();
    double x_eval=(2*x_first+h)/2;
    int N=GetNumberofPartitions();
    int M=GetNumberofPartitionsY();
    double sum=0;
    if(M==0) {
        for (int i = 0; i < N; i++) {
            sum += Function(x_eval);
            x_eval = x_eval + h;
        }
        result=sum*h;
        return result;
    }
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


