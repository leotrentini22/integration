//
// Created by Leonardo Trentini on 25/11/2022.
//

//File with the methods for the class Domain defined in "domain.hpp" -- not finished
#include "domain.hpp"
#include <cassert>
#include <vector>
#include <algorithm>
Domain::Domain(){

    intervals[0][0]=0.0;
    intervals[0][1]=0.0;
    intervals[1][0]=0.0;
    intervals[1][1]=0.0;
}

// Domain in 2D: [a,b][c,d]
Domain::Domain(double (*v)[2]) {
    intervals[0][0]=v[0][0];
    intervals[0][1]=v[0][1];
    intervals[1][0]=v[1][0];
    intervals[1][1]=v[1][1];
}

Domain::Domain(double a, double b, double c, double d) {
    intervals[0][0] = a;
    intervals[0][1] = b;
    intervals[1][0] = c;
    intervals[1][1] = d;
}
// Domain in 1D: [a,b]
Domain::Domain(double a, double b) {
    intervals[0][0]=a;
    intervals[0][1]=b;
}

//Check the domain:
void Domain::checkDomain(){
    assert((intervals[0][0])<=(intervals[0][1]) && (intervals[1][0])<= (intervals[1][1])); //a<=b and c<=d
}

//access to the intervals:
auto* Domain::getIntervals() {
    return intervals;
}

void Domain::grid() {
    // Calculate the partition interval H
    double H = (intervals[0][0]-intervals[0][1])/M;
    // Create a vector of xk values:
    std::vector<double> xk;
    for(int k=0; k<=M; k++){
        xk.push_back(intervals[0][0] + k*H);
    }
}