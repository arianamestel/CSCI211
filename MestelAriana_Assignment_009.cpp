//MestelAriana_Assignment_009
/****
  Problem: The problem is to write a function “integrate” with prototype:
  The purpose if this assignment is to see (and implement) a very simple
  application of function pointers.

  Ideas: Integrate the line, square, and cube funtions into the integrate
  function.  Keep adding the sum of the areas until the variable reaches
  its max.  Use the fucntions within the integrate function.

****/

#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double line(double n) {
  return n;
}

double square(double n) {
  return n * n;
}

double cube(double n) {
  return n * n * n;
}

double integrate(FUNC f, double a, double b) {
  double sum = 0;
  for (double i = a; i <= b; i += .0001) {
    sum += f(i) * .0001;;
  }
  return sum;
}

int main() {
  cout<< "The integral of f(x)=x between 1 and 5 is: " <<integrate(line, 1, 5)<<endl;
  cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
  cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
  return 0;
}
