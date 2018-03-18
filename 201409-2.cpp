#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  bool map[101][101] = {0};
  while (n--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = x1+1; i <= x2; i++) {
      for (int j = y1+1; j <= y2; j++) {
        map[i][j] = true;
      }
    }
  }

  int count = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (map[i][j]) {
        count++;
      }
    }
  }
  cout << count << endl;
}