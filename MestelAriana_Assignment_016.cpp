//MestelAriana_Assignment_016.cpp
/*****
  Problem: Write a program that inputs two integers n and k, where n>=k.
  Your program should calculate the number of different ways that k bishops
  could be placed on an nXn chessboard.  Structure your program using the
  backtracking scheme that we have used for the eight queens problem. What
  needs to be modified is the “OK” function.
  Ideas: Use the same structure as the 8 queens and 8 cross programs to figure out the
  the amount of bishops that could fit on the board.  Change the logic in the ok
  function to make it work for the bishops.
*****/
#include <iostream>
using namespace std;

bool ok(int q[], int k, int n) {
  //identify the row and column the bishop is in
   int row = q[k]/n, column = q[k]%n, current_row, current_column;

   for(int i=0; i<k; i++){ //for every bishop
       current_row = q[i]/n;
       current_column = q[i]%n;

       //diagonal test
       if(abs(row-current_row)==abs(column-current_column)) return false;
   }

   return true;
}

void backtrack(int &c) {
  c--;
  if (c == -1) exit(0);
}

void print(int counter, int n, int k) {
  cout << "On a " << n << " by " << n << " board, there are " << counter << " solutions when there are " << k << " bishops." << endl;
}

int main () {
  int n, k, c = 0, counter = 0, b;
  cout << "Enter two integers, where the first one is bigger than or equal to the next: ";
  cin >> n >> k;
  if (n == -1) return 0;
  while (true) { // until all solutions are found
    b = 0, counter = 0, c = 0;
    int * q = new int[k];
    q[b] = 0;
    while (b < k) { // for each bishop
      while (q[b] < n * n) {
        if (ok(q, b, n)) break;
        else q[b]++;
      }
      if (q[b] == n * n) {
        counter++;
        print(counter, n, b);
        backtrack(c);
        q[b]++;
      }
      else {
        int t = q[b];
        b++;
        q[b] = t;
      }
    }
    counter++;
    backtrack(c);
    q[b]++;
  }

  return 0;
}
