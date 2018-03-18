#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Windows {
  int x1;
  int x2;
  int y1;
  int y2;
  int order;
  int number;
  Windows() {
    x1 = x2 = y1 = y2 = 0;
    order = -1;
  }
  bool operator<(const Windows& other) const {
    return (order < other.order);
  }
};

std::vector<Windows> inWindow(Windows windows[], int n, int x, int y) {
  std::vector<Windows> v;
  for (int i = 1; i <=n; i++) {
    if (x >= windows[i].x1 && x <= windows[i].x2 
      && y >= windows[i].y1 && y <= windows[i].y2) {
      v.push_back(windows[i]);
    }
  }
  return v;
}

int main() {
  int N, M;
  cin >> N >> M;
  Windows windows[N+1];
  for (int i = 1; i <= N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    windows[i].x1 = x1;
    windows[i].y1 = y1;
    windows[i].x2 = x2;
    windows[i].y2 = y2;
    windows[i].number= i;
    windows[i].order = N-i+1;
  }

  while (M--) {
    int click_x, click_y;
    cin >> click_x >> click_y;
    std::vector<Windows> tmp = inWindow(windows, N, click_x, click_y);
    if (tmp.size() == 0) {
      cout << "IGNORED" << endl;
    }
    else {
      sort(tmp.begin(), tmp.end());
      /*测试tmp*/
      /*
      for(int k = 0; k < tmp.size(); k++) {
        cout << tmp[k].number << " " << tmp[k].order << endl;
      }
      */
      cout << tmp[0].number << endl;
      for (int i = 1; i<= N; i++) {
        if (windows[i].number == tmp[0].number) {
          windows[i].order = 1;
        }
        else {
          windows[i].order++;
        }
      }
    }
  }
  return 0;
}