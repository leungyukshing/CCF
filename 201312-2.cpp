#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isNumber(char ch) {
  if (ch >= '0' && ch <= '9')
    return true;

  return false;
}

int main() {
  string str;
  cin >> str;

  std::vector<char> v;
  for (int i = 0; i < str.size() - 1; i++) {
    if (isNumber(str[i])) {
      v.push_back(str[i]);
    }
  }

  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += (v[i] - '0') * (i + 1);
  }
  int code = sum % 11;
  if (code == 10) {
    if (str[str.size() - 1] == 'X') {
      cout << "Right" << endl;
    }
    else {
      str[str.size() - 1] = 'X';
      cout << str << endl;
    }
  }
  else {
    if (str[str.size() - 1] == code + '0') {
      cout << "Right" << endl;
    }
    else {
      str[str.size() - 1] = code + '0';
      cout << str << endl;
    }
  }
  return 0;
}