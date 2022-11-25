//
// Created by Leonardo Trentini on 25/11/2022.
//
#ifndef DOMAIN_HPP_
#define DOMAIN_HPP_

#include <ostream>
class Domain{
private:
    double intervals[2][2];
public:
    Domain();
    Domain(double v[2][2]);
    Domain(double a, double b, double c, double d);
    Domain(double a, double b);
    ~Domain();
    void checkDomain();
    double* getIntervals();
};

#endif /* DOMAIN_HPP_ */