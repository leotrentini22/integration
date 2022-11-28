//
// Created by Odile on 25.11.2022.
//

//Structure for now, working in 1 Dimension:
// AbstractIntegrator = Abstract class of integrators, with 3 derived classes
// MidpointIntegrator, TrapezoidalIntegrator, SimpsonIntegrator

//next things to do:
// - computing accuracy
// - extend for function chosen by the user, without coding
// - extend for stranger domains
// - let the possibility for the user to calculate another integral without restarting the program
// - plot


#include <iostream>
#include <cmath>
#include <fstream>
#include "domain.hpp"
#include "function.hpp"
#include "AbstractIntegrator.hpp"
#include "MidpointIntegrator.hpp"
#include "TrapezoidalIntegrator.hpp"
#include "SimpsonIntegrator.hpp"


// here you can set whatever function you would like to integrate, 1 Dimension
double f_to_integrate(double x,double y) { return x*sqrt(y)*cos(y+x); }

int main(){

    // set domain extremes, 1 Dimension
    double initialX = 0.0;
    double finalX = 1.0;
    double initialY = 0.0;
    double finalY = 1.0;

    AbstractIntegrator *pIntegration = 0;

    // set number of partitions for x and for y

    double N=100;
    double M=100;

    // to change Integrator, put "new NameIntegrator" as below (Name = Midpoint, Trapezoidal or Simpson)

    // Midpoint Integrator
    pIntegration = new MidpointIntegrator;
    pIntegration->SetNumberOfPartitions(N,M);
    pIntegration->SetExtremes(initialX,finalX, initialY,finalY);
    pIntegration->SetFunction(f_to_integrate);

    double result_midpoint;
    result_midpoint = pIntegration->Integrate();

    // Trapezoidal Integrator
    pIntegration = new TrapezoidalIntegrator;
    pIntegration->SetNumberOfPartitions(N,M);
    pIntegration->SetExtremes(initialX,finalX, initialY,finalY);
    pIntegration->SetFunction(f_to_integrate);

    double result_trapezoidal;
    result_trapezoidal = pIntegration->Integrate();

    // Simpson Integrator
    pIntegration = new SimpsonIntegrator;
    pIntegration->SetNumberOfPartitions(N,M);
    pIntegration->SetExtremes(initialX,finalX, initialY,finalY);
    pIntegration->SetFunction(f_to_integrate);

    double result_simpson;
    result_simpson = pIntegration->Integrate();

    // print the results to the screen
    std::cout<<result_midpoint<<" "<<result_trapezoidal<<" "<<result_simpson;

    //you can also write down the result into a file, with the method "WriteResult" of Abstract Integrator

    return 0;
}


// I was just trying to understand how to get function from input, not working


void getinput(){
    int a,b;
    do{
    std::cout<<"Choose the function to use. Insert: \n 1 = polinomial \n 2 = sinusoidal \n 3 = exponential \nThen press ENTER";
    std::cin>>a;}while(a<0 || a>3);
    if(a==1){
        std::cout<<"Choose the function to use. Insert: \n 1 = x \n 2 = x^2 \n 3 = sqrt(x) \nThen press ENTER";
        std::cin>>b;
    }
    else if(a==2){
        std::cout<<"Choose the function to use. Insert: \n 1 = cos(x) \n 2 = sin(x) \nThen press ENTER";
        std::cin>>b;
    }
    else if(a==3){
        std::cout<<"Choose the function to use. Insert: \n 1 = exp(x) \n 2 = exp(-x) \nThen press ENTER";
        std::cin>>b;
    }


}




