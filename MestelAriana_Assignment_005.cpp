// MestelAriana_Assignment_005.cpp
/*****
 Problem: Redo the 8 queens 1 dimensional array program with backtracking
 REMOVING ALL "GOTOs" - but implementing the same algorithm

 Ideas: Use a bool funtion to judge is the array is valid, Use
 a print funtion to print when ever a solution is found, and
 use a backtrack funtion to backtrack the column (if it reaches -1
 then there are no more solutions).  In the main funtion there should be
 a nexted while loop that will continue as long as the column is
 above or equale to zero.  If the it gets to the last column then it should
 print and backtrack to find another solution.  Otherwise, it should
 start from the begining of the next row. this should loop until ALL
 solutions are found.
*****/


#include <iostream>
using namespace std;

bool ok(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if ((q[c] == q[i] || ((c - i) == abs(q[c] - q[i])))) return false;
  }
  return true;
}
void print(int q[], int &counter) {
  counter++;
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (q[c] == r) cout << "1" << " ";
      else cout << "0" << " ";
    }
    cout << endl;
 }
 cout << "Solution #" << counter << endl;
}

void backtrack(int &c) {
  c--;
  if (c == -1) exit(0);
}

int main () {
  int c = 0, counter = 0, q[8];
  q[0] = 0;
  while (c != -1) {
    c++; // NC
    if (c == 8) {
      print(q, counter);
      backtrack(c);
    }
    else q[c] = -1;
    while (c != -1) {
      q[c]++;
      if (q[c] == 8) backtrack(c);
      else if (ok(q, c) == true) break;
    }
  }

return 0;
}
