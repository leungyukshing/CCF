#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
  int key;
  int value;
  Pair(int _key, int _value) {
    key = _key;
    value = _value;
  }
  bool operator<(const Pair &other) const {
    if (value < other.value)
      return true;
    else if (value == other.value && key > other.key)
      return true;

    return false;
  }
};
int main() {
  int n;
  cin >> n;

  std::vector<Pair> v;
  while (n--) {
    int num;
    cin >> num;

    bool isFound = false;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].key == num) {
        v[i].value++;
        isFound = true;
        break;
      }
    }
    if (!isFound) {
      v.push_back(Pair(num, 1));
    }
  }

  sort(v.rbegin(), v.rend());

  cout << v[0].key << endl;
  return 0;
}