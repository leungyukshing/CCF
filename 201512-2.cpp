#include <iostream>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  int map[n][m];
  bool elimination[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      elimination[i][j] = false;
    }
  }

  int color;
  int count;

  /*行扫描*/
  for (int i = 0; i < n; i++) {
    color = map[i][0];
    count = 1;
    for (int j = 1; j < m; j++) {
      if (map[i][j] == color) {
        count++;
      }
      else {
        if (count >= 3) {
          while (count) {
            elimination[i][j - count] = true;
            count--;
          }
        }
        count = 1;
        color = map[i][j];
      }
      /*边界情况*/
      if (j == m-1) {
        if (count >= 3) {
          while (count) {
            elimination[i][j - count + 1] = true;
            count--;
          }
        }
      }
    }
  }

  /*列扫描*/
  for (int i = 0; i < m; i++) {
    color = map[0][i];
    count = 1;
    for (int j = 1; j < n; j++) {
      if (map[j][i] == color) {
        count++;
      }
      else {
        if (count >= 3) {
          while (count) {
            elimination[j - count][i] = true;
            count--;
          }
        }
        count = 1;
        color = map[j][i];
      }
      /*边界情况*/
      if (j == n-1) {
        if (count >= 3) {
          while (count) {
            elimination[j - count + 1][i] = true;
            count--;
          }
        }
      }
    }
  }

  /*输出*/
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (elimination[i][j]) {
        cout << "0 ";
      }
      else {
        cout << map[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}