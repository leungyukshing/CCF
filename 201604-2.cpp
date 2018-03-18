#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
  Point() {
    x = y = 0;
  }
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};

int main() {
  int map[15][10];
  Point add_on[4];
  int count = 0;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int tmp;
      cin >> tmp;
      if (tmp == 1) {
        add_on[count].x = i;
        add_on[count].y = j;
        count++;
      }
    }
  }

  int diff;
  cin >> diff;
  for (int i = 0; i < 4; i++) {
    add_on[i].y += (diff - 1);
  }

  bool flag = true;
  int drop_dis = 0;
  count = 0;
  while (flag == true) {
    for (int i = 0; i < 4; i++) {
      if (map[add_on[i].x + drop_dis + 1][add_on[i].y] == 0) {
        count++;
      }
    }

    if (count == 4) {
      drop_dis++;
      count = 0;
    }
    else {
      // 填充
      for (int i = 0; i < 4; i++) {
        map[add_on[i].x + drop_dis][add_on[i].y] = 1;
      }
      flag = false;
    }
  }
  
  for (int i = 0 ; i < 15; i++) {
    for (int j = 0; j < 9; j++) {
      cout << map[i][j] << " ";
    }
    cout << map[i][9] << endl;
  }

  return 0;
}