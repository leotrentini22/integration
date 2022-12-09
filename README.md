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
Class of the methods to use in the main.

### Integrator
Regroups the different numerical classes to integrate the function. Other integration methods can be implemented following the model of AbstractIntegrator.
Available classes are:
- `Midpoint integrator`
- `Trapezoidal integrator`
- `Cavalieri-Simpson integrator`

### Function
Regroups the different classes to get the function from user. Other classes to get the function can be implemented following the model of AbstractFunction.
Available methods:
- get the function from input in the terminal using `ParserFunction`
- get the function by writing it directly in the code using `ForderFunction`
- get the function by composing it using `CodedFunction`

### Test
To do

## Usage
First of all, you need to clone the repository
```Bash
git clone https://github.com/leotrentini22/integration.git
```
Then, build and run `main.cpp` (with Clion or in the terminal) and follow the instructions on the screen

<p align="right">(<a href="#top">Back to top</a>)</p>
