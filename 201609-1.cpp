#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  int diff[n-1];
  for (int j = 0; j < n-1; j++) {
    diff[j] = abs(num[j+1] - num[j]);
  }

  int max = diff[0];

  for (int k = 0; k < n-1; k++) {
    if (diff[k] > max) {
      max = diff[k];
    }
  }
  cout << max << endl;
  return 0;
}