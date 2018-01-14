// MestelAriana_Assignment_014.cpp
/*****
  Problem: Using the recursive eight queens (see handout section on web site) as a model, redo
  the cross problem using recursion 
  Ideas:  Use the psuedo code given by Dr Waxman tp redo the cross problem
  and the stable marriage problem.  Dont use backtrack because the
  recursion will naturally do so.
*****/
#include <iostream>
using namespace std;

bool ok(int q[], int c) {
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
    for (int x = 0; x < c; x++) {
      if (q[c] == q[x]) return false;
    }
    if (abs(q[a[c][i]] - q[c]) == 1) return false;
    i++;
  }
  return true;
}
void print(int q[]) {
  static int counter = 0;
  counter++;
  cout << "Solution #" << counter << endl;
  cout << " " << q[0] << q[1] << " " << endl;
  cout << q[2] << q[3] << q[4] << q[5] << endl;
  cout << " " << q[6] << q[7] << endl;
}

void move(int q[], int c) {
  if (c == 8) {
    print(q);
    return;
  }
  for (int i = 1; i < 9; i++) {
    q[c] = i;
    if(ok(q, c)) move(q, c + 1);
  }

}

int main () {
  int q[8];
  move(q, 0);
  return 0;
}
