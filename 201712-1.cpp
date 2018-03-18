#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int num;
  cin >> num;
  int arr[num];
  int i = 0;
  int n = num;
  while (n--) {
    cin >> arr[i++];
  }

  sort(arr, arr+num);

  int diff[num - 1];
  for (int j = 0; j < num-1; j++) {
    diff[j] = arr[j+1] - arr[j];
  }

  int min;
  if (num > 2) {
    min = arr[1] - arr[0];
    for (int k = 0; k < num-1; k++) {
      if (diff[k] < min)
        min = diff[k];
    }
  }
  else {
    min = diff[0];
  }

  cout << min << endl;
  return 0;
}