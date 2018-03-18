#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  int count = 0;
  for (int i = 1; i < n-1; i++) {
    if ((num[i-1] < num[i] && num[i] > num[i+1]) || (num[i-1] > num[i] && num[i] < num[i+1])) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}