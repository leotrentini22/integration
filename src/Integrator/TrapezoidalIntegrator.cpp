// methods for Trapezoidal Integrator - 1D and 2D

#include "TrapezoidalIntegrator.hpp"
#include <cmath>

// Constructor and Destructor

TrapezoidalIntegrator::TrapezoidalIntegrator() {}

TrapezoidalIntegrator::~TrapezoidalIntegrator() {}


//integration

double TrapezoidalIntegrator::Integrate() {

    double x_first=GetFirstExtreme();
    double h=GetStepSize();//Size of interval
    double xold=x_first;
    double xnew=x_first+h;
    int N=GetNumberofPartitions(); //Number of partition in x
    int M=GetNumberofPartitionsY();//Number of partition in y
    double sum=0;

    //implementation 1D (M = partitions for y == 0)
    if(M==0) {
        for (int i = 0; i < N; i++) {
            sum += Function(xold) + Function(xnew); //Function gives the value of the function evaluated in xold or xnew
            xold = xnew;
            xnew = xnew + h;
        }
        result=sum*h/2;
        return result;
    }

    // implementation 2D
    double y_first=GetFirstExtremeY();
    double x_last=GetFinalExtremeX();
    double y_last=GetFinalExtremeY();
    double k=GetStepSizeY();
    double yold;
    xold=xold+k;
    for (int i = 1; i < N; i++) {
        yold=y_first+k;
        for (int j = 1; j < M; j++){
            sum += Function(xold,yold);
            yold = yold+k;
        }
        xold=xold+h;
    }
    sum=sum*4;
    sum+=Function(x_first,y_first)+Function(x_first,y_last)+Function(x_last,y_first)+Function(x_last,y_last);
    xold=x_first+h;
    yold=y_first+k;
    for (int i = 1; i < N; i++) {
        sum+=2*(Function(xold,y_first)+Function(xold,y_last));
        xold=xold+h;
    }
    for (int j = 1; j < M; j++){
        sum += 2*(Function(x_first,yold)+Function(x_last,yold));
        yold = yold+k;
    }
    result = sum * h/2 * k/2;
    return result;

}

