//
// Created by Leonardo Trentini on 02/12/2022.
//
#include "CodedFunction.hpp"
#include <cmath>
#include <iostream>
#include <vector>

CodedFunction::CodedFunction() {}
CodedFunction::~CodedFunction() {}

double CodedFunction::getFunctionElement(double x) {
    return x;
}

void CodedFunction::SetFunction(int d) {}

double CodedFunction::getFunctionElement(double x, double y) {
    return x*y;
}