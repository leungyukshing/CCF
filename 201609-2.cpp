#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q[21];
  int no = 1;
  for (int i = 1; i <= 20; i++) {
    q[i].push(no++);
    q[i].push(no++);
    q[i].push(no++);
    q[i].push(no++);
    q[i].push(no++);
  }

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    bool finish = false;

    // find consecutive seats
    for (int row = 1; row <= 20; row++) {
      if (q[row].size() >= num) {
        for (int j = 0; j < num; j++) {
          cout << q[row].front() << " ";
          q[row].pop();
        }
        finish = true;
        break;
      }
    }

    if (!finish) {
      for (int row = 1; row <= 20 && num > 0; row++) {
        while (num > 0 && !q[row].empty()) {
          cout << q[row].front() << " ";
          q[row].pop();
          num--;
        }
      }
    }
    cout << endl;
  }

  return 0;
}