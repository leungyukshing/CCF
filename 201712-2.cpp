#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  int k;

  cin >> n >> k;

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  int num = 0; // 报数
  while (v.size() > 1) {
    n = v.size();
    int len = 0;
    for (int i = 0; i < n; i++) {
      ++num;
      if (num % k && num % 10 != k) {
        v[len++] = v[i];
      }
    }
    if (len == 0) {
      v[len++] = v.back();
    }
    v.resize(len);
  }

  cout << v[0] << endl;
  return 0;
}