//
// Created by Odile on 03.12.2022.
//


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

Initialization::Initialization() {

}

Initialization::~Initialization() {}
/**
void Initialization::SetDimension() {
    /**Set dimension of the function to integrate
    do{
        std::cout<<"Set the dimension (1 or 2): ";
        std::cin>> d;}while(d<1||d>2); //not sure if it is working mayby we should right what is above:
}
**/


void Initialization::SetDimension() {
    /**Set dimension of the function to integrate**/
    int dim = 0;
    do {
        std::cout << "Set the dimension (1 or 2): ";
        std::cin >> dim;
    } while (dim < 1 || dim > 2);
    d = dim;
}

/**
void Initialization::SetDomainExtremes() {
    /** Set domain extremes
    double Xi, Xf, Yi, Yf;
    int Npart,Mpart;
    std::cout<<"\nSet the parameters for the x axes:\ndomain extremes [a,b] \nN = Number of partitions for x";
    do{
        std::cout<<"\nSet a: ";
        std::cin>> Xi;
        std::cout<<"\nSet b: ";
        std::cin>> Xf;}while(Xi>Xf);
    std::cout<<"\nSet N (it has to be integer and positive): ";
    std::cin>> Npart;
    if (Npart<0){Npart=100;}
    initialX = Xi;
    finalX = Xf;
    N = Npart;

    // if 2D, we inizialize y
    if(d==2){
        std::cout<<"\nSet the parameters for the y axes:\ndomain extremes [c,d] \nM = Number of partitions for y";
        do{
            std::cout<<"\nSet c: ";
            std::cin>> Yi;
            std::cout<<"\nSet d: ";
            std::cin>> Yf;}while(Yi>Yf);
        std::cout<<"\nSet M (it has to be integer and positive): ";
        std::cin>> Mpart;
        if (Mpart<0){Mpart=100;}}

    initialY = Yi;
    finalY = Yf;
    M = Mpart;
}
**/

void Initialization::SetDomainExtremes(){
    /** Set domain extremes**/

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
        if (M<0){M=100;}
    }
}


void Initialization::ChooseMethod() {
    /**Choose the method that will be used to calculate the integral**/
    do{
        std::cout<<"\nSet method to integrate:\n - insert 1 for Midpoint \n - insert 2 for Trapezoidal \n - insert 3 for Cavalieri-Simpson\nif input is not 1, 2 or 3, will be used 1 as standard\nMETHOD: ";
        std::cin>> m;
    }while(m<0||m>3);
}
/**
void Initialization::ChooseMethod() {
    /**Choose the method that will be used to calculate the integral
    int mchoose;

    do{
        std::cout<<"\nSet method to integrate:\n - insert 1 for Midpoint \n - insert 2 for Trapezoidal \n - insert 3 for Cavalieri-Simpson\nif input is not 1, 2 or 3, will be used 1 as standard\nMETHOD: ";
        std::cin>> mchoose;
    }while(mchoose<0||mchoose>3);
    m = mchoose;
}**/

double Initialization::CalculateIntegral() {
    /**Depending on the method choosen, calculate the integral of the function**/
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

}

void Initialization::PrintResult() {
    /** print the results to the screen**/
    std::cout<<"result = "<<result;
}









    //you can also write down the result into a file, with the method "WriteResult" of Abstract Integrator

    return 0;
}




