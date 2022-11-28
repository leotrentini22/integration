//
// Created by Odile on 25.11.2022.
//

//Structure:
// AbstractIntegrator = Abstract class of integrators, with 3 derived classes
// MidpointIntegrator, TrapezoidalIntegrator, SimpsonIntegrator

//next things to do:
// - computing accuracy -> accuracy can be plotted if we know the exact integral
// - extend for function chosen by the user, without coding
// - extend for stranger domains
// - let the possibility for the user to calculate another integral without restarting the program
// - plot


//HOW TO RUN
//to change the function to integrate, change "f_to_integrate" (line 34) (keep attention to the dimension chosen)
//then click "build", "run" and follow the instructions on the screen


#include <iostream>
#include <cmath>
#include <fstream>
#include "domain.hpp"
#include "function.hpp"
#include "AbstractIntegrator.hpp"
#include "MidpointIntegrator.hpp"
#include "TrapezoidalIntegrator.hpp"
#include "SimpsonIntegrator.hpp"


// here you can set whatever function you would like to integrate
// 1D -> double f_to_integrate(double x) { return x; }
// 2D
double f_to_integrate(double x,double y) { return x*y; }


// here you can compose your function:
double setfunction(double x){
    double function=x;
    int f = 0;
    double c = 0.0;

    while(f>=0) {
        std::cout<< "Choose sin = 1, cos = 2, exp = 3, add a constant = 4, multiply by a constant = 5 or stop =-1 "<< std::endl;
        std::cin >> f;
        if (f == 1) {
            function = sin(function);
        }
        if (f == 2) {
            function = cos(function);
        }
        if (f == 3) {
            function = exp(function);
        }
        if (f == 4){
            std::cout<<"Value of the constant added: "<< std::endl;
            std::cin>> c;
            function = function + c;
        }
        if (f == 5){
            std::cout<<"Value of the constant: "<< std::endl;
            std::cin>> c;
            function = function*c;
        }
    }
    return function;
}

int main(){

    //initialize variables
    double initialX, finalX, initialY, finalY = 0.0;
    double N,M;
    int d,m;
    double result;

    //set dimension
    do{
    std::cout<<"Set the dimension (1 or 2): ";
    std::cin>> d;}while(d<1||d>2);

    // set domain extremes
    std::cout<<"\nSet the parameters for the x axes:\ndomain extremes [a,b] \nN = Number of partitions for x";
    do{
    std::cout<<"\nSet a: ";
    std::cin>> initialX;
    std::cout<<"\nSet b: ";
    std::cin>> finalX;}while(initialX>finalX);
    std::cout<<"\nSet N (it has to be integer and positive): ";
    std::cin>> N;
    if (N<0){N=100;}

    // if 2D, we inizialize y
    if(d==2){
        std::cout<<"\nSet the parameters for the y axes:\ndomain extremes [c,d] \nM = Number of partitions for y";
        do{
            std::cout<<"\nSet c: ";
            std::cin>> initialY;
            std::cout<<"\nSet d: ";
            std::cin>> finalY;}while(initialY>finalY);
        std::cout<<"\nSet M (it has to be integer and positive): ";
        std::cin>> M;
        if (M<0){M=100;}}

    do{
        std::cout<<"\nSet method to integrate:\n - insert 1 for Midpoint \n - insert 2 for Trapezoidal \n - insert 3 for Cavalieri-Simpson\nif input is not 1, 2 or 3, will be used 1 as standard\nMETHOD: ";
        std::cin>> m;
    }while(m<0||m>3);

    AbstractIntegrator *pIntegration = 0;

    if(m==2){
    // Trapezoidal Integrator
    pIntegration = new TrapezoidalIntegrator;
    if(d==2){
        pIntegration->SetNumberOfPartitions(N,M);
        pIntegration->SetExtremes(initialX,finalX, initialY,finalY);
    }
    else{
        pIntegration->SetNumberOfPartitions(N);
        pIntegration->SetExtremes(initialX,finalX);
    }
    pIntegration->SetFunction(f_to_integrate);

    result = pIntegration->Integrate();}

    else if(m==3){
    // Simpson Integrator
    pIntegration = new SimpsonIntegrator;
    if(d==2){
            pIntegration->SetNumberOfPartitions(N,M);
            pIntegration->SetExtremes(initialX,finalX, initialY,finalY);
        }
    else{
            pIntegration->SetNumberOfPartitions(N);
            pIntegration->SetExtremes(initialX,finalX);
        }
    pIntegration->SetFunction(f_to_integrate);

    result = pIntegration->Integrate();}

    else{
        // Midpoint Integrator
        pIntegration = new MidpointIntegrator;
        if(d==2){
            pIntegration->SetNumberOfPartitions(N,M);
            pIntegration->SetExtremes(initialX,finalX, initialY,finalY);
        }
        else{
            pIntegration->SetNumberOfPartitions(N);
            pIntegration->SetExtremes(initialX,finalX);
        }
        pIntegration->SetFunction(f_to_integrate);

        result = pIntegration->Integrate();
    }

    // print the results to the screen
    std::cout<<"result = "<<result;

    //you can also write down the result into a file, with the method "WriteResult" of Abstract Integrator

    return 0;
}



