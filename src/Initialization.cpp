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


// Constructor
Initialization::Initialization()
   : initialX(), finalX(), initialY(), finalY(), N(), M(), d(), m(), result() {
    this->pfunction = 0;
}

//Destructor
Initialization::~Initialization() {
    delete pfunction;
}



void Initialization::SetDimension() {
    /** Set dimension of the function to integrate. Dimension can be 1 or 2. */
    int dim = 0;
    do {
        //Enter the dimension in the terminal. Dimension is stored in the variable d.
        std::cout << "Set the dimension (1 or 2): ";
        std::cin >> dim;
        if (dim < 1 || dim > 2){
            //If dimension entered is wrong, it sends this message
            std::cout << "\nDimension not 1 or 2! Retry\n";
        }
    } while (dim < 1 || dim > 2);
    d = dim;
}

void Initialization::SetParameters(){
    /** Set domain extremes and number of partitions*/
    //Enter in the terminal a and b (extremes of the x axis) and the number of partition N.
    //a and b are stored in the variable initialX and finalX respectively. Partition is stored in N.
    std::cout<<"\nSet the parameters for the x axes:\ndomain extremes [a,b] \nN = Number of partitions for x";
    do{
        //Set a and b
        std::cout<<"\nSet a: ";
        std::cin>> initialX;
        std::cout<<"\nSet b: ";
        std::cin>> finalX;
        if (initialX>finalX){
            //Wrong input
            std::cout << "\nDomain not valid, a>b! Retry\n";
        }
    }while(initialX>finalX);

    do{
        // Set N
    std::cout<<"\nSet N (it has to be integer and positive): ";
    std::cin>> N;
        if (N==0){
            //Wrong input
            std::cout << "\nN not valid, null! Retry\n";
        }
    if (N<0){
        std::cout << "\nN not valid, negative! Retry\n";
    }
    }while(N<1);

    // If we are in 2D: Initiate the extremes on y axis and number of partition
    //M: nummber of partition in y
    //initialY: c
    //finalY: d
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
    //choice of method is stored in the variable m.
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
     * - ForderFunction = function assembled step by step from user
     * - CodedFunction = function directly coded (need to be recompiled everytime)
     */

    //if you want to change method to get the function from user, change the code here
    //not choosable from user, in order to avoid undesirable errors

    pfunction = new ForderFunction;
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

    delete pIntegration;
    //Result of the integration is stored in the variable result
    return result;
}

void Initialization::PrintResult() const {
    /** print the results to the screen */
    std::cout<<"result = "<<result;
}













