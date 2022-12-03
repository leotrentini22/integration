//
// Created by Odile on 25.11.2022.
//


// next things to do:
// - check if "ForderFunction" works correctly
// - implement "ParserFunction"
// - implement "ForderFunction" and "ParserFunction" and in 2D
// - make the main more readable
// - Doxygen
// - Tests

// extras
// - extend for stranger domains
// - let the possibility for the user to calculate another integral without restarting the program
// - plot

//Structure:
// AbstractIntegrator = Abstract class of integrators, with 3 derived classes
// MidpointIntegrator, TrapezoidalIntegrator, SimpsonIntegrator

// AbstractFunction = Abstract class of function, with 3 derived classes (ways of getting function from user)
// ForderFunction, ParserFunction, CodedFunction


//HOW TO RUN
//click "build", "run" and follow the instructions of the screen


#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "domain.hpp"
#include "AbstractFunction.hpp"
#include "ForderFunction.hpp"
#include "ParserFunction.hpp"
#include "AbstractIntegrator.hpp"
#include "MidpointIntegrator.hpp"
#include "TrapezoidalIntegrator.hpp"
#include "SimpsonIntegrator.hpp"
#include "Initialization.hpp"


// here you can set whatever function you would like to integrate
// 1D -> double f_to_integrate(double x) { return x; }
// 2D
//double f_to_integrate(double x,double y) { return x*y;}



int main(){

/**
    //initialize variables
    double initialX, finalX, initialY=0.0, finalY = 0.0;
    int N,M=0;
    int d,m=1;
    double result=0.0;

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


    AbstractFunction *pfunction;
    pfunction = new ParserFunction;
    pfunction -> SetFunction();


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
    pIntegration->SetFunction(pfunction);

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
    pIntegration->SetFunction(pfunction);

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
        pIntegration->SetFunction(pfunction);

        result = pIntegration->Integrate();
    }

    // print the results to the screen
    std::cout<<"result = "<<result;

    //you can also write down the result into a file, with the method "WriteResult" of Abstract Integrator
**/


    Initialization parameter;
    parameter.SetDimension();

    return 0;
}



