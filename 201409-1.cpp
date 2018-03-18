#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }

  std::vector<int> v;
  while (n--) {
    int value;
    cin >> value;
    v.push_back(value);
  }
  sort(v.begin(), v.end());
  for (int j = 0; j < v.size() - 1; j++) {
    arr[j] = v[j+1] - v[j];
  }

  int count = 0;
  for (int k = 0; k < v.size() - 1; k++) {
    if (arr[k] == 1) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}