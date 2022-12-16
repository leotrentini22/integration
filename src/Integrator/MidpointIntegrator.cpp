// methods for Midpoint Integrator - 1D and 2D

#include "MidpointIntegrator.hpp"
#include <cmath>

// constructor and destructor

MidpointIntegrator::MidpointIntegrator() {}

MidpointIntegrator::~MidpointIntegrator() {}


// integration

double MidpointIntegrator::Integrate() {

    //Initiate the parameter
    double x_first=GetFirstExtreme();
    double h=GetStepSize(); //Interval size
    double x_eval=(2*x_first+h)/2; //Value on which we evaluated our function
    int N=GetNumberofPartitions();// Number of partition on x-axis
    int M=GetNumberofPartitionsY();// Number of partition on y-axis
    double sum=0;

    //Implementation 1D (M == 0)
    if(M==0) {
        for (int i = 0; i < N; i++) {
            sum += Function(x_eval); //Function(x) gives the value of the function at x_eval
            x_eval = x_eval + h; //increase the value of x_eval
        }
        result=sum*h;
        return result;
    }

    // Implementation 2D
    double y_first=GetFirstExtremeY();
    double k=GetStepSizeY();// Interval size on y-axis
    double y_eval;
    for (int i = 0; i < N; i++) {
        y_eval=(2*y_first+k)/2; //y value on which we evaluate the function
        for (int j = 0; j < M; j++){
            sum += Function(x_eval,y_eval);
            y_eval = y_eval + k;
        }
        x_eval = x_eval + h;
    }

    result = sum * h * k;
    return result;
}


