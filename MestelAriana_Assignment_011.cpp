// MestelAriana_Assignment_011.cpp
/*****
  Question: Why does the program get increasingly slower for
  each successive value of i?
  This program uses recurtion and as it gets bigger and bigger
  it has to keep getting slower at giving a result.  This can
  be due to the fact that the program has to make many activation
  records and pop them after to get baxck to the begining.
  Question: What technique can we use to speed it up? Write the code?
  To speed it up we can write the code using iteration. the code using
  iteration will be in my program

*****/

#include<iostream>
using namespace std;

long fib(int n) {
  long a = 1, b = 1, c = 1;
  for (int i = 3; i <= n; i++) {
    a = b + c;
    b = c;
    c = a;
  }
  return a;
}

int main () {
  for (int i = 1; i <= 70; i++)
    cout << "fib(" << i << ") = " <<  fib(i) << endl;
  return 0;
}
