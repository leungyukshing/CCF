#include <iostream>
using namespace std;

int matrix[1000][1000];

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int a = n - 1; a >= 0; a--) {
    for (int b = 0; b < m; b++) {
      cout << matrix[b][a] << " ";
    }
    cout << endl;
  }

  return 0;
}