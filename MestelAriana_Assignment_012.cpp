// MestelArian_Assignment_012.cpp
/*****
  Problem: You are given three towers a, b, and c. We start with n rings on tower a and we
  need to transfer them to tower b subject to the following restrictions:
  The Algorithm:
1. Find the candidate.
2. Move the candidate (right or left, depending if the number of rings is odd or even) to the
   closest tower on which it can be placed. Move "around the circle" if necessary.
3. If not done, go back to step 1.

    Ideas:  Use the psuedo code given by Dr. Waxman as a guide to help
    write the code.  Use vecotrs instead of array because there are helpful funtions
    that will be useful to this problem.
****/

#include <iostream>
#include <vector>
using namespace std;

int main () {
  vector<int>t[3];
  int n, move = 0;
  cout << "Please enter an ODD number of rings to move: ";
  cin >> n;
  cout << endl;
  for (int i = n + 1; i >= 1; i--)
    t[0].push_back(i);
  t[1].push_back(n + 1);
  t[2].push_back(n + 1);

  int from = 0, to = 1, candidate = 1;
  while (t[1].size() < (n + 1)) {
    cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower "
    << char(from + 65) << " to tower " << char(to + 65) << endl;
    t[to].push_back(t[from].back());
    t[from].pop_back();
    if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) from = (to + 1) % 3;
    else from = (to + 2) % 3;
    candidate = t[from].back();
    if (candidate % 2 == 1) to = (from + 1) % 3;
    else to = (from + 2) % 3;

  }
  return 0;
}
