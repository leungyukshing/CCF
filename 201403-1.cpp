#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  std::vector<int> v;
  while (N--) {
    int val;
    cin >> val;
    v.push_back(val);
  }

  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] + v[j] == 0) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}