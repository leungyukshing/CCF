#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  if (T <= 3500) {
    cout << T << endl;
    return 0;
  }
  
  for (int i = 3600; i <= 200000; i += 100) {
    int subtract = 0;
    if (i >= 3600 && i <= 5000) {
      subtract += (i - 3500) * 0.03;
    }
    if (i >= 5100 && i <= 8000) {
      subtract += (i - 5000) * 0.1 + 45;
    }
    if (i >= 8100 && i <= 12500) {
      subtract += (i - 8000) * 0.2 + 45 + 300;
    }
    if (i >= 12600 && i <= 38500) {
      subtract += (i - 12500) * 0.25 + 45 + 300 + 900;
    }
    if (i >= 38600 && i <= 58500) {
      subtract += (i - 38500) * 0.3 + 45 + 300 + 900 + 6500;
    }
    if (i >= 58600 && i <= 83500) {
      subtract += (i - 58500) * 0.35 + 45 + 300 + 900 + 6500 + 6000;
    }
    if (i >= 83600) {
      subtract += (i - 83500) * 0.45 + 45 + 300 + 900 + 6500 + 6000 + 8750;
    }

    if (subtract + T == i) {
      cout << i << endl;
      return 0;
    }
  }

}