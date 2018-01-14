// MestelAriana_Assignment_006.cpp
/*****
  Problem: Write a program which allocates the integers 1-8 to the
  squares in the figure above, subject to the restrictions that no
  two adjacent squares contain consecutive integers.

  Ideas: Treat this like the 8 queens problem but change the logic
  in the ok funtion.  The ok funtion will have an array which will
  indicate where adjacent boxes are and will return false if it is.
  The Ok funtion will also have to make sure that none of the
  numbers are already being used.  The print funtion will have to
  print the the numbers in the right shape. And the backtack funtion
  will go back a space if c gets to 9.
*****/

#include <iostream>
using namespace std;

bool ok(int q[], int c) {
  for (int x = 0; x < c; x++) {
    if (q[c] == q[x]) return false;
  }
  int a[8][5] = {{-1},
                 {0, -1},
                 {0, -1},
                 {0, 1, 2, -1},
                 {0, 1, 3, -1},
                 {1, 4, -1},
                 {2, 3, 4, -1},
                 {3, 4, 5, 6, -1}};
  int i = 0;
  while (a[c][i] != -1) {
    if (abs(q[a[c][i]] - q[c]) == 1) return false;
    i++;
  }
  return true;
}

void backtrack(int &c) {
  c--;
  if (c == -1) exit(0);
}

void print(int q[], int &counter) {
  counter++;
  cout << "Solution #" << counter << endl;
  int i = 0;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 4; c++) {
      if (((r == 0) && (c == 0))  || ((r == 0) && (c == 3)) || ((r == 2) && ( c == 0))  || ((r == 2) && ( c == 3))) cout << "  ";
      else {
        cout << q[i] << " ";
        i++;
      }
    }
    cout << endl;
  }
}

int main () {
  int c = 0, q[8], counter = 0, i = 0;
  q[0] = 1;
  while (c != -1) {
    c++;
    if (c == 8) {
      print(q, counter);
      backtrack(c);
    }
    else q[c] = 0;
    while (c != -1) {
      q[c]++;
      if (q[c] == 9) backtrack(c);
      else if (ok(q, c) == true) break;
    }
  }
return 0;
}
