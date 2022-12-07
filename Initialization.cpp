//
// Created by Odile on 03.12.2022.
//


#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "Function/AbstractFunction.hpp"
#include "Function/ForderFunction.hpp"
#include "Function/ParserFunction.hpp"
#include "Integrator/AbstractIntegrator.hpp"
#include "Integrator/MidpointIntegrator.hpp"
#include "Integrator/TrapezoidalIntegrator.hpp"
#include "Integrator/SimpsonIntegrator.hpp"
#include "Initialization.hpp"
//#include <gtest/gtest.h>


Initialization::Initialization()
   : initialX(), finalX(), initialY(), finalY(), N(), M(), d(), m(), result() {
    this->pfunction = nullptr;
}

Initialization::~Initialization() {
    delete pfunction;
}



void Initialization::SetDimension() {
    /** Set dimension of the function to integrate */
    int dim = 0;
    do {
        std::cout << "Set the dimension (1 or 2): ";
        std::cout<<std::endl;
        std::cin >> dim;
    } while (dim < 1 || dim > 2);
    d = dim;
}

void Initialization::SetParameters(){
    /** Set domain extremes */

    std::cout<<"\nSet the parameters for the x axes:\ndomain extremes [a,b] \nN = Number of partitions for x";
    do{
        std::cout<<"\nSet a: ";
        std::cin>> initialX;
        std::cout<<"\nSet b: ";
        std::cin>> finalX;
        // try to test the googletest: does not work
        //EXPECT_TRUE(initialX<finalX)<<"Error: a>b. Expected a<b.";
    }while(initialX>finalX);
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
    /** Choose the method that will be used to calculate the integral */
    do{
        std::cout<<"\nSet method to integrate:\n - insert 1 for Midpoint \n - insert 2 for Trapezoidal \n - insert 3 for Cavalieri-Simpson\nif input is not 1, 2 or 3, will be used 1 as standard\nMETHOD: ";
        std::cin>> m;
    }while(m<0||m>3);
}


void Initialization::SetFunctionToIntegrate() {
    /**here you choose how to set the function
     * ParserFunction = function from string
     * ForderFunction =function assembled step by step from user
     * CodedFunction = function directly coded (need to be recompiled everytime)
     */

    pfunction = new ParserFunction;
    pfunction -> SetFunction(d);
}

double Initialization::CalculateIntegral() {
    /** Depending on the method chosen, calculate the integral of the function */

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
    return result;
}

void Initialization::PrintResult() const {
    /** print the results to the screen */
    std::cout<<"result = "<<result;
}













