#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int cakes[n];

  for (int i = 0; i < n; i++) {
    cin >> cakes[i];
  }

  int friends_have_cakes = 0;
  int j = 0;
  while (j < n) {
    int per_person_take = cakes[j];
    while (per_person_take < k && j < n) {
      j++;
      per_person_take += cakes[j];
    }
      friends_have_cakes++;
    j++;
  }

  cout << friends_have_cakes << endl;
}