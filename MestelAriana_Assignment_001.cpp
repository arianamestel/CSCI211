// MestelAriana_Assignment_001.cpp
/******
  Assignment 1: Perfect Square Problem
  Find the Value
  Write a program to find and print the first perfect square (i*i) whose last two digits are both odd.

  There is no such thing as a perfect square whose last two digits are both odd.  To prove this, the
  program will keep adding to the value of n to see when the last two digits of its square are both odd.
  The program will keep looping anf never find an answer because it is not possible.
  To make this program work, n cannot be an int because it isnt large enough and will stop at 65537.
  To fix this i stores the variable n as long.

*******/
#include <iostream>
using namespace std;

int main () {
  long n = 1;
  while (true) {
    long square = n * n;
    if ((square > 9) && (square % 2 == 1) && ((square / 10) % 2 == 1)) {
      cout << n * n << " is a perfect square whose last two digits are odd." << endl;
      break;
    }
    else {
      n++;
    }
    if (n > 100000) {
      cout << "There is no such thing as a perfect square whose last two digits are odd." << endl;
      break;
    }
  }
  return 0;
}
