#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int num = 0;
  while (N >= 50) {
    N -= 50;
    num += 7;
  }
  while (N >= 30) {
    N -= 30;
    num += 4;
  }
  while (N >= 10) {
    N -= 10;
    num++;
  }
  cout << num << endl;

  return 0;
}