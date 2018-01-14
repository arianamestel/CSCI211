// MestelAriana_Assignment_008.cpp
/*****
  Problem: Modify the Eight Queens program (1 dimensional array – no goto
  version) so that it prints out a chessboard with some “fancy” representation
  of a queen in the appropriate positions.
  Ideas: Take the fancy chessboard program and incorperate it into the print
  funtion.  If a queen is supposed to go to a white box then a black queen will be
  printed and vice vera.
****/

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
  cout << "Solution #" << counter << endl;

  int i, j, k, l;
  typedef char box[5][7];
  box bb, wb, *board[8][8];
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 7; j++) {
      wb[i][j] = ' ';
      bb[i][j] = char(219);
    }
  }
  box bq = {{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
              {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
              {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
              {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
              {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
  box wq = {{' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
              {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
              {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
              {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
              {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }};
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if ((j + i) % 2 == 0) {
        if (q[j] == i) board[i][j] = &wq;
        else board[i][j] = &wb;
      }
      else {
        if (q[j] == i) board[i][j] = &bq;
        else board[i][j] = &bb;
      }
    }
  }
  cout << "   ";
  for (i = 0; i < 7 * 8; i++) {
    cout << '_';
  }
  cout << endl;
  for (i = 0; i < 8; i++) {
    for (k = 0; k < 5; k++) {
      cout << "   " << char(179);
      for (j = 0; j < 8; j++) {
        for (l = 0; l < 7; l++) {
          cout << (*board[i][j])[k][l];
        }
      }
      cout << char(179) << endl;
    }
  }

  cout << "   ";
  for (i = 0; i < 7* 8; i++) {
    cout << char(196);
  }
  cout << endl;

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
