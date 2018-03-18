#include <iostream>
using namespace std;

int main() {
  int year, day;
  cin >> year >> day;

  bool isLeapYear = false;
  if (year % 4 == 0  && year % 100 != 0) {
    isLeapYear = true;
  }
  if (year % 400 == 0) {
    isLeapYear = true;
  }

  if (isLeapYear) {
    int daysInMonth[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
    for (int i = 0; i <= 12; i++) {
      if (day == daysInMonth[i]) {
        cout << i << endl;
        cout << daysInMonth[i] - daysInMonth[i-1];
        break;
      }
      if (day >= daysInMonth[i] && day < daysInMonth[i+1]) {
        cout << i+1 << endl;
        cout << day - daysInMonth[i];
        break;
      }
    }
  }
  else {
    int daysInMonth[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    for (int i = 0; i <= 12; i++) {
      if (day == daysInMonth[i]) {
        cout << i << endl;
        cout << daysInMonth[i] - daysInMonth[i-1];
        break;
      }
      if (day > daysInMonth[i] && day < daysInMonth[i+1]) {
        cout << i+1 << endl;
        cout << day - daysInMonth[i];
        break;
      }
    }  
  }
  return 0;
}