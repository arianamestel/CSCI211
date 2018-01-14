// MestelAriana_Assignment_004.cpp
/*****
  Problem: Complete the 8 queens 2 dimensional array program with backtracking that we worked on in class.

  Ideas: Use the notes and goto statment instead of a lot of loops to go to the next column or row. If one
  reult does not work, then use the goto statment to go to the next row or column.  Use backtrack when the
  column or row goes off the board to try for a new valid solution. Make a print label to print out the valid solution.
  Then use backtrack to go find the other possible solutions.  Once the column number goes to -1 then all the possible
  solutions have been found.

*****/

#include <iostream>
using namespace std;

int main () {
  int i, c = 0, r, counter = 0;
  int b[8][8] = {0};
  b[0][0] = 1;
NC: c++;
  if (c == 8) goto Print;
  r = -1;
NR: r++;
  if (r == 8) goto Backtrack;
  // row test
  for (i = 0; i < c; i++)
    if (b[r][i] == 1) goto NR;
  // Up diagnal test
  for (i = 1; (c - i) >= 0 && (r - i) >= 0; i++)
    if (b[r - i][c - i] == 1) goto NR;
  // Down diagnal test
  for (int i = 1; (c - i) >= 0 && (r + i) < 8; i++)
    if (b[r + i][c - i] == 1) goto NR;
  b[r][c] = 1;
  goto NC;
Backtrack: c--;
  if (c == - 1) return 0;
  r = 0;
  while (b[r][c] != 1)
    r++;
  b[r][c] = 0;
  goto NR;
Print: for (int r = 0; r < 8; r++) {
         for (int c = 0; c < 8; c++) {
           cout << b[r][c] << " ";
         }
         cout << endl;
       }
  counter++;
  cout << "Solution #" << counter << endl;
  goto Backtrack;
}
