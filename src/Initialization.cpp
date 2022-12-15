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
    // Method through which the user sets dimension of the function to integrate. Dimension can be 1 or 2

    int dim = 0;
    do {

        //Set dimension d
        std::cout << "Set the dimension (1 or 2): ";
        std::cin >> dim;

        if (dim < 1 || dim > 2){
            //If wrong dimension (not 1 or 2), user has to retry
            std::cout << "\nDimension not 1 or 2! Retry\n";
        }

    } while (dim < 1 || dim > 2);
    d = dim;
}

void Initialization::SetParameters(){
    // Method that sets domain extremes and number of partitions
    //The user has to enter a and b (extremes of the x axis) and the number of partitions N

    std::cout<<"\nSet the parameters for the x axes:\ndomain extremes [a,b] \nN = Number of partitions for x";
    do{
        //Set a and b
        std::cout<<"\nSet a: ";
        std::cin>> initialX;
        std::cout<<"\nSet b: ";
        std::cin>> finalX;

        if (initialX>finalX){
            //If wrong input (a>b, impossible), user has to retry
            std::cout << "\nDomain not valid, a>b! Retry\n";
        }
    }while(initialX>finalX);

    do{
        // Set N
        std::cout<<"\nSet N (it has to be integer and positive): ";
        std::cin>> N;

        if (N==0){
            //If wrong input (N null), user has to retry
            std::cout << "\nN not valid, null! Retry\n";
        }
        if (N<0){
            //If wrong input (N negative), user has to retry
            std::cout << "\nN not valid, negative! Retry\n";
        }
    }while(N<1);


    // If we are in 2D, we initialize also the extremes (c,d) and number of partitions (M) on y axis

    if(d==2){
        std::cout<<"\nSet the parameters for the y axes:\ndomain extremes [c,d] \nM = Number of partitions for y";

        do{
            // set c and d
            std::cout<<"\nSet c: ";
            std::cin>> initialY;
            std::cout<<"\nSet d: ";
            std::cin>> finalY;

            if (initialY>finalY){
                //If wrong input (c>d, impossible), the user is asked to retry
                std::cout << "\nDomain not valid, c>d! Retry\n";
            }
        }while(initialY>finalY);

        do{
            //set M
            std::cout<<"\nSet M (it has to be integer and (strictly) positive): ";
            std::cin>> M;
            if (M==0){
                //If wrong input (M null), user has to retry
                std::cout << "\nM not valid, null! Retry\n";
            }
            if (M<0){
                //If wrong input (M negative), user has to retry
                std::cout << "\nM not valid, negative! Retry\n";
            }
        }while(M<1);
    }
}


void Initialization::ChooseMethod() {

    // Choose the numerical algorithm that will be used to calculate the integral
    //This choice is stored in the variable m
    do{
        std::cout<<"\nSet method to integrate:\n - insert 1 for Midpoint \n - insert 2 for Trapezoidal \n - insert 3 for Cavalieri-Simpson\nMETHOD: ";
        std::cin>> m;
        if (m<1||m>3){
            //If wrong input (m not 1, 2 or 3), user has to retry
            std::cout<<"\nMethod not valid, it has to be 1, 2 or 3! Retry\n";
        }
    }while(m<1||m>3);
}


void Initialization::SetFunctionToIntegrate() {

    pfunction = new ParserFunction; // to change the behaviour, change this line
    pfunction -> SetFunction(d); // abstract method of Abstract Function
}

double Initialization::CalculateIntegral() {

    //method that initialize the calculation and returns result

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
        //"else" is to set it as standard integrator (if m, the numerical algorithm, is somehow not chosen)

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

    std::cout<<"result = "<<result;
}













