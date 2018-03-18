#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  
  sort(num, num + n);

  int mid = n / 2;
  std::vector<int> left;
  std::vector<int> right;
  for (int i = 0 ; i < mid; i++) {
    if (num[i] < num[mid]) {
      left.push_back(num[i]);
    }
  }

  for (int j = mid + 1; j < n; j++) {
    if (num[j] > num[mid]) {
      right.push_back(num[j]);
    }
  }

  if (left.size() == right.size()) {
    cout << num[mid] << endl;
  }
  else {
    cout << -1 << endl;
  }
  return 0;
}