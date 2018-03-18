#include <iostream>
#include <vector>
using namespace std;

int findIndex(std::vector<int> v, int target) {
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  std::vector<int> v(n+1);
  for (int i = 1; i <= n; i++) {
    v[i] = i;
  }

  while (m--) {
    int num, dis;
    cin >> num >> dis;

    int target_index = findIndex(v, num);
    int to_exchange = v[target_index+dis];
    
    if (dis < 0) {
      for (int index = target_index; index > target_index+dis; index--) {
        v[index] = v[index-1];
      }
    }
    else {
      for (int index = target_index; index < target_index+dis; index++) {
        v[index] = v[index+1];
      }
    }
    v[target_index+dis] = num;
  }

  for (int j = 1; j < n; j++) {
    cout << v[j] << " ";
  }
  cout << v[n] << endl;
  return 0;
}