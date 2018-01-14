// MestelAriana__Assignment_013.cpp
/*****
  Problem: You have n men and n woman, and their preference rankings
  of each other, and you need to match them up so that the total matching
  is “stable.”
  Ideas:
*****/

#include <iostream>
using namespace std;

bool ok(int q[], int c) {
  static int mp[3][3] = {0, 2, 1,   // man 0
                         0, 2, 1,  // man 1
                         2, 1, 0}; // man 2
  static int wp[3][3] = {2, 1, 0,  // woman 0
                         0, 1, 2,  // woman 1
                         2, 1, 0}; // woman 2
  for (int i = 0; i < c; i++) {
    if (q[c] == q[i]) return false;
  }
  for (int i = 0; i < c; i++) {
    if ((mp[c][i] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i])) return false;
    if ((wp[c][i] < wp[c][q[c]]) && (mp[q[i]][c] < mp[q[i]][i])) return false;
  }
  return true;
}
void backtrack(int &c) {
  c--;
  if (c == -1) exit(0);
}
void print(int q[]) {
  static int counter = 0;
  counter++;
  cout << "Solution #" << counter << endl;
  cout << "Man       Woman" << endl;
  for (int i = 0; i < 3; i++) {
    cout << " " << i << "          " << q[i] << endl;
  }
}
int main () {
  int c = 0, q[3], n = 3;
  q[0] = 0;
  while (c != -1) {
    c++;
    if (c == n) {
      print(q);
      backtrack(c);
    }
    else q[c] = -1;
    while (c != -1) {
      q[c]++;
      if (q[c] == n) backtrack(c);
      else if (ok(q, c)) break;
    }

  }
  return 0;

}
