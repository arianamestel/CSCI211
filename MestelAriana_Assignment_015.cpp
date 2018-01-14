#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;
static int trace[rows][cols] = {0};
int step[rows][cols] = {0};
int w[rows][cols] = {{3,4,1,2,8,6},
                     {6,1,8,2,7,4},
                     {5,9,3,9,9,5},
                     {8,4,1,3,2,6},
                     {3,7,2,8,6,4}};

int min (int a, int b, int c) {
  int min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  return min;
}


int cost(int i, int j) {
  if (j == 0) return trace[i][j] = w[i][0];
  if (trace[i][j] != 0) return trace[i][j];
  int left = cost(i, j - 1);
  int up = cost(((i - 1 + 5) % 5), (j - 1));
  int down = cost(((i + 1 + 5) % 5),(j - 1));
  int minimum = min(left, up, down);
  return trace[i][j] = w[i][j] + minimum;
}


int main () {
  int q[rows], path[cols];
  for (int i = 0; i < rows; i++) {
    q[i] = cost(i, cols - 1);
  }
  int min = q[0];
  int min_i = 0;
  for (int i = 0; i < rows; i++) {
    if (q[i] < min) {
      min = q[i];
      min_i = i;
    }
  }

  cout << "The shortest path is of length " << min << " " << endl;

  return 0;
}
