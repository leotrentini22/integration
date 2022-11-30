//
// Created by Leonardo Trentini on 25/11/2022.
//

//File with the methods for the class Function defined in "function.hpp" -- not finished
#include "function.hpp"
#include <vector>
#include <cmath>


Function::Function() {

}

double Function::getFunctionElement (double x,std::vector<int> forder,std::vector<int> corder){
    double function = x;
    int i;
    int j=0;
    for (i =0; i<=forder.size();i++) {
        int f = forder[i];
        int c = corder[j];

        if (f == 1) {
            function = sin(function);
        }
        if (f == 2) {
            function = cos(function);
        }
        if (f == 3) {
            function = exp(function);
        }
        if (f == 4) {
            function = function + c;
            j++;
        }
        if (f == 5) {
            function = function * c;
            j++;
        }
        else{
            function = x;
        }

    }
    return function;
}