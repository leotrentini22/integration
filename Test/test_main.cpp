//
// Created by Odile on 25.11.2022.
//

/**
 * Test of "Main" in order to check if everything works correctly
 */


#include "../Function/AbstractFunction.hpp"
#include "../Initialization.hpp"
#include <cassert>


int main(){
    // Bound of the domain
    double initialX, finalX, initialY, finalY;

    //N and M are the number of partition for x and y
    int N,M;

    //d: dimension of the function to integrate
    int d;
    //m: method to integrate (1 Midpoint, 2: Trapezoidal, 3: Cavalieri-Simpson)
    int m;

    Initialization init;

    init.SetDimension();
    d=init.GetDimension();
    assert(d > 0 && d < 3);

    init.SetParameters();
    initialX=init.GetInitialX();
    finalX=init.GetFinalX();
    N=init.GetN();
    assert(initialX<finalX);
    assert(N>0);
    if(d==2){
        initialY=init.GetInitialY();
        finalY=init.GetFinalY();
        M=init.GetM();
        assert(initialY<finalY);
        assert(M>0);
    }

    init.ChooseMethod();
    m=init.GetMethod();
    assert(m>0&&m<4);

    init.SetFunctionToIntegrate();
    init.CalculateIntegral();
    init.PrintResult();

    return 0;
}
