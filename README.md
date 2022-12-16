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
    <li><a href="#Structure">Structure</a></li>
    <li><a href="#Usage">Usage</a></li>
  </ol>
</details>


## General Information

The repository contains the code and report for the Programming Concepts in Scientific Computing (MATH-458) project, an implementation of three different methods for the numerical computation of integrals in one or two dimensions


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
   Then just follow the instructions on screen!


## Structure

For a complete view of our work, please see the `Report`

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

### Test
We implemented two different tests on our program. 
In `test_integrators` we evaluate the accuracy of our numerical methods using [Google Tests](http://google.github.io/googletest/), with a certain tolerance of precision.
In `test_main` we check the validity of Initialization class, throughout a series of assertions that evaluate if, given wrong inputs by the user, our methods behave as expected.

### Doxygen
In `doxyfile`, we provide instructions in order to build a complete and documented html page for our project.
To use it, first you need to install [Doxygen](https://www.doxygen.nl/download.html). Then open our `doxyfile` with Doxywizard (installed within Doxygen) and run.


## Possible developments
Our program can be easily extended to more dimensions.

It would be possible also to add more numerical methods, following the pattern provided by AbstractIntegrator.

Moreover, the code can be extended to stranger domains. This implies that a new abstract class should be created so that the way to get the domain can be changed easily. The domain might be passed as a function, using Function Parser class. Then this domain can be divided in simpler domains, assembled by union.

In addition, our program might be extended to work in complex domains. However, this extension would require to investigate better how does integration work in the theory of complex spaces. 

<p align="right">(<a href="#top">Back to top</a>)</p>
