//
// Created by Odile on 25.11.2022.
//

//It would be nice to make the domain as concise as possible, here an idea
#include <iostream>
#include <fstream>
#include "domain.hpp"
#include "function.hpp"
#include "AbstractIntegrator.hpp"
#include "MidpointIntegrator.hpp"

double fRhs(double x) { return 1; }

int main(){
    double initialX = 0.0;
    double finalX = 1.0;

    AbstractIntegrator *pIntegration = 0;

    // Solving with forward-Euler
    double N=10;
    pIntegration = new MidpointIntegrator;
    pIntegration->SetNumberOfPartitions(N);
    pIntegration->SetExtremes(initialX,finalX);
    pIntegration->SetFunction(fRhs);

    double result;
    result = pIntegration->Integrate();
    std::cout<<result;

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




