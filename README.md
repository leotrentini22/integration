<div id="top"></div>

<br />
<div align="center">
<h1 align="center">Numerical Integration</h1>
  <p align="center">
    Programming Concepts in Scientific Computing (MATH-458)
  </p>
</div>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#General-Information">General Information</a></li>
    <li><a href="#Our-Team">Our Team</a></li>
    <li><a href="#Usage">Usage</a></li>
    <li><a href="#Structure">Structure</a></li>
    <li><a href="#Tests">Tests</a></li>
    <li><a href="#Possible developments">Possible developments</a></li>
  </ol>
</details>


## General Information

The repository contains the code and report for the Programming Concepts in Scientific Computing (MATH-458) project, an implementation of three different algorithms for the numerical computation of integrals in one or two dimensions.

In particular, this project aims at computing:
```math
I =\int_{\Omega}f(\textbf{x}) d\textbf{x}
    \quad\quad\quad\quad\quad\quad\quad\quad\quad\quad\quad\quad\text{with}\quad \Omega=(a,b)\times(c,d)  
```
Using either Midpoint, Trapezoidal or Cavalieri-Simpson numerical algortihms.


## Our Team

- Leonardo Trentini: [@leotrentini22](https://github.com/leotrentini22)
- Odile Montarnal: [@Dod-il](https://github.com/Dod-il)


## Usage
1. First of all, you need to clone the repository
```Bash
git clone https://github.com/leotrentini22/integration.git
```
2. Then, build and run `main.cpp`. This can be done with and IDE (we used [Clion](https://www.jetbrains.com/clion/)), or directly in the terminal, by going to the folder where you cloned our repository and typing these commands:
```Bash
   mkdir build
   cd build
   cmake ..
   make
   ./main
```

Finally, just follow the instructions on screen!


## Structure

For a complete view of our work, please see the `Report` and [Doxygen documentation](#Doxygen).

### Main
Interface with the user. All calculations are done here. It is written as concise as possible: all the set up is done in Initialization

### Initialization
Class of the methods to use in the main in order to set up the problem and run calculations

### Integrator
Regroups the different numerical classes to integrate the function. Other integration methods can be implemented following the model of AbstractIntegrator.
Available classes are:
- `MidpointIntegrator`
- `TrapezoidalIntegrator`
- `SimpsonIntegrator`

### Function
Regroups the different classes to get the function from user. Other classes to get the function can be implemented following the model of AbstractFunction.
Available methods:
- get the function from input in the terminal using `ParserFunction`
- get the function by writing it directly in the code using `CodedFunction`
- get the function by composing it using `ForderFunction`

For `ParserFunction`, we used an [external library](http://warp.povusers.org/FunctionParser/)

### Doxygen
In `doxyfile`, we provide instructions in order to build a complete and documented html page for our project.
To use it, first you need to install [Doxygen](https://www.doxygen.nl/download.html). Then open our `doxyfile` with Doxywizard (installed within Doxygen) and run.

## Test
We implemented two different tests on our program. 
In `test_integrators` we evaluate the accuracy of our numerical methods using [Google Tests](http://google.github.io/googletest/), with a certain tolerance of precision.
In `test_main` we check the validity of Initialization class, throughout a series of assertions that evaluate if, given wrong inputs by the user, our methods behave as expected.


## Possible developments
During our work, we found some developments that might be done, although we preferred to concentrate our efforts on a precise task and leave these developments for a future attempt.

In particular, here is a list of possible extensions:
   - extend to more dimensions.
   - add more numerical methods (for example, the [Booles Rule](https://mathworld.wolfram.com/BoolesRule.html))
   - extend to stranger domains
   - extend to work in complex domains. However, this extension would require to investigate better how does integration work in the [theory of complex analysis](https://books.google.ch/books?id=yl3GIXd3dFIC&q=%22calculus+of+residues%22&pg=PP12&redir_esc=y) 

<p align="right">(<a href="#top">Back to top</a>)</p>
