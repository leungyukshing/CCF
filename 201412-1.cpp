#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> m;
  map<int, int>::iterator it;
  while (n--) {
    int num;
    cin >> num;
    it = m.find(num);
    /*该key不存在*/
    if (it == m.end()) {
      m[num] = 1;
      cout << 1 << " ";
    }
    else {
      m[num]++;
      cout << m[num] << " ";
    }
  }
  cout << endl;
  return 0;
}