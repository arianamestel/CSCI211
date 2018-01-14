//MstelAriana_Assignment_002.cpp
/*****
Problem:
Write a function: bool equivalent(int a[], int b[], int n)
which takes two arrays a and b of length n and returns true is
they are shift equivalent and false otherwise.

Ideas:
Use nested loops to figure out if the arrays are shift equivalent.
Set up a testing variable that will count if the values in the arrays
are the same. in the nested for loop test each number of the first
array by a variable plus one modulo capacity to shift through everything.
If they are equal it will return true.
*****/

#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n) {
  int test;
  for (int x = 0; x < n; x++) {
    test = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i] == b[(j + 1) % n]) test++;
      }
    }
    if (test == n) return true;
  }
  return false;
}

int main () {
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {3, 4, 5, 1, 2};
  if (equivalent(a, b, 5)) {
    cout << "They are equal." << endl;
  }
  else {
    cout << "They are not equal." << endl;
  }
  return 0;
}
