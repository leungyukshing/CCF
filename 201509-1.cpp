#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  int i = 0;
  int section_number = 0;
  while (i < n) {
    int present = num[i];
    int j = i + 1;
    while (j < n) {
      if (num[j] == present) {
        j++;
      }
      else {
        break;
      }
    }
    section_number++;
    i = j;
  }
  cout << section_number << endl;
}