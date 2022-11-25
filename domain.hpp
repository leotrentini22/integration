//
// Created by Leonardo Trentini on 25/11/2022.
//

//I defined a class Domain, maybe we should add "grid" or make onther class "grid"?

#ifndef DOMAIN_HPP_
#define DOMAIN_HPP_

#include <ostream>
#include <cassert>
class Domain{
private:
    double intervals[2][2];
    int M;
public:
    // Constructor:
    Domain();
    Domain(double v[2][2]);
    Domain(double a, double b, double c, double d);
    Domain(double a, double b);

    //Destructor:
    ~Domain();

    //Method:
    void checkDomain();
    auto* getIntervals();
    void grid();
};

#endif /* DOMAIN_HPP_ */