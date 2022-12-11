//
// Created by Odile on 03.12.2022.
//

// methods for Initialization class


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
        std::cin >> dim;
        if (dim < 1 || dim > 2){
            std::cout << "\nDimension not 1 or 2! Retry\n";
        }
    } while (dim < 1 || dim > 2);
    d = dim;
}

void Initialization::SetParameters(){
    /** Set domain extremes and number of partitions*/

    std::cout<<"\nSet the parameters for the x axes:\ndomain extremes [a,b] \nN = Number of partitions for x";
    do{
        std::cout<<"\nSet a: ";
        std::cin>> initialX;
        std::cout<<"\nSet b: ";
        std::cin>> finalX;
        if (initialX>finalX){
            std::cout << "\nDomain not valid, a>b! Retry\n";
        }
    }while(initialX>finalX);

    do{
    std::cout<<"\nSet N (it has to be integer and positive): ";
    std::cin>> N;
        if (N==0){
            std::cout << "\nN not valid, null! Retry\n";
        }
    if (N<0){
        std::cout << "\nN not valid, negative! Retry\n";
    }
    }while(N<1);

    // if 2D, we inizialize y
    if(d==2){
        std::cout<<"\nSet the parameters for the y axes:\ndomain extremes [c,d] \nM = Number of partitions for y";
        do{
            std::cout<<"\nSet c: ";
            std::cin>> initialY;
            std::cout<<"\nSet d: ";
            std::cin>> finalY;
            if (initialY>finalY){
                std::cout << "\nDomain not valid, c>d! Retry\n";
            }
        }while(initialY>finalY);
        do{
            std::cout<<"\nSet M (it has to be integer and (strictly) positive): ";
            std::cin>> M;
            if (M==0){
                std::cout << "\nM not valid, null! Retry\n";
            }
            if (M<0){
                std::cout << "\nM not valid, negative! Retry\n";
            }
        }while(M<1);
    }
}


void Initialization::ChooseMethod() {
    /** Choose the numerical method that will be used to calculate the integral */
    do{
        std::cout<<"\nSet method to integrate:\n - insert 1 for Midpoint \n - insert 2 for Trapezoidal \n - insert 3 for Cavalieri-Simpson\nMETHOD: ";
        std::cin>> m;
        if (m<1||m>3){
            std::cout<<"\nMethod not valid, it has to be 1, 2 or 3! Retry\n";
        }
    }while(m<1||m>3);
}


void Initialization::SetFunctionToIntegrate() {
    /**Choose method to get function from user and set the function.
     * - ParserFunction = function from string
     * - ForderFunction = function assembled step by step from user (not implemented for 2D)
     * - CodedFunction = function directly coded (need to be recompiled everytime)
     */

    //if you want to change method to get the function from user, change the code here
    //not choosable from user, in order to avoid undesirable errors
    pfunction = new ParserFunction;
    pfunction -> SetFunction(d);
}

double Initialization::CalculateIntegral() {
    /** Depending on the method chosen, calculate the integral of the function
     * \return result
     */

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
        //"else" is just to set it as standard integrator (if m is somehow not chosen)

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













