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

## Structure

Link to doxygene: make a link

### main
Interface with the user. All calculations are done here.

### Initialization
Class of the function to use in the main.

### Integrator
Regroups the different method to integrate the function. Other integration method can be implemented following the model of AbstractIntegrator.
Available methods are:
- Midpoint method
- Trapezoidal method
- Cavalieri-Simpson

### Function
Regroups the different method to get the function. Other methods to get the function can be implemented following the model of AbstractFunction.
Available methods:
- get the function from input in the terminal
- get the function by writing it directly in the code
- get the function by composing it

### Test
To do

## Usage
```Bash
git clone https://github.com/leotrentini22/integration.git
```
Open the file "main.cpp" and run it.
