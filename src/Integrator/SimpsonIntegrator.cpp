// methods for Simpson Integrator - 1D and 2D

#include "SimpsonIntegrator.hpp"
#include <cmath>

// Constructor and Destructor

SimpsonIntegrator::SimpsonIntegrator() {}

SimpsonIntegrator::~SimpsonIntegrator() {}


// integration

double SimpsonIntegrator::Integrate() {

    double x_first=GetFirstExtreme();
    double h=GetStepSize();//Size of interval
    double xold=x_first;//values of x that we need to evaluate the function
    double xnew=x_first+h;
    int N=GetNumberofPartitionsX();// Number of partition on x
    int M=GetNumberofPartitionsY();// Number of partition on y
    double sum = 0;
    // implementation 1D (M = partitions for y == 0)
    if(M==0) {
        for (int i = 0; i < N; i++) {
            sum += Function(xold) + Function(xnew) + 4 * Function((xold + xnew) / 2); //Function(x) gives the value of the function at x_eval
            xold = xnew;
            xnew = xnew + h;
        }

        result = sum * h / 6;
        return result;
    }

    // implementation 2D
    double y_first=GetFirstExtremeY();
    double k=GetStepSizeY();// size of interval
    double yold;
    double S=1.0; //Coefficient that "weight" the function depending on the position on the grid
    for (int i = 0; i < N+1; i++) {
        yold=y_first;
        for (int j = 0; j < M+1; j++){
            S=getCoeffS(i, j, N, M);
            sum += Function(xold,yold)*S;
            yold=yold+k;
        }
        xold=xold+h;
    }
    return sum*h*k/9;


}


double SimpsonIntegrator::getCoeffS(int i, int j, int Nx, int My){

    if((i==0&&j==0)||(i==0&&j==(My-1))||(i==(Nx-1)&&j==0)||(i==(Nx-1)&&j==(My-1))){
        return 1;
    }
    else if(((i+1)%2)==0&&((j+1)%2)==0){
        return 16;
    }
    else if((i==0&&((j+1)%2)==0)||(j==0&&((i+1)%2)==0)||(i==(Nx-1)&&((j+1)%2)==0)||(j==(My-1)&&((i+1)%2)==0)){
        return 4;
    }
    else if((i==0)||(j==0)||(i==(Nx-1))||(j==(My-1))){
        return 2;
    }
    else if(((i+1)%2)!=0&&((j+1)%2)!=0){
        return 4;
    }
    else{
        return 8;
    }
}




