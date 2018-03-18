#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair {
  int key;
  int value;

  Pair(int _key, int _value) {
    key = _key;
    value = _value;
  }

  bool operator<(const Pair& other) const {
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
  int size = n;
  std::vector<Pair> v;

  while (n--) {
    int key;
    cin >> key;
    
    bool isFound = false;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].key == key) {
        v[i].value++;
        isFound = true;
        break;
      }
    }
    if (!isFound) {
      v.push_back(Pair(key, 1));
    }
  }

  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i].key << " " << v[i].value << endl;
  }
  return 0;
}