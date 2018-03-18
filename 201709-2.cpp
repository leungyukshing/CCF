#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Action {
public:
  int room;
  int time;
  int operation;
  Action(int _room, int _time, int _operation) {
    room = _room;
    time = _time;
    operation = _operation;
  }

  bool operator<(const Action &other) const {
    if (time < other.time)
      return true;
    else if (time == other.time && operation < other.operation)
      return true;
    else if (time == other.time && operation == other.operation && room < other.room)
      return true;

    return false;
  }
};

int main() {
  int N, K;
  cin >> N >> K;

  std::vector<Action> actions;
  std::vector<int> keys(N+1);

  for (int i = 1; i <= N; i++) {
    keys[i] = i;
  }

  while (K--) {
    int room, begin, length;
    cin >> room >> begin >> length;
    actions.push_back(Action(room, begin, 1));
    actions.push_back(Action(room, begin+length, 0));
  }

  sort(actions.begin(), actions.end());

  for (int i = 0; i < actions.size(); i++) {
    Action act = actions[i];
    if (act.operation == 0) {
      /*靠左放置钥匙*/
      for (int n = 1; n <= N; n++) {
        if (keys[n] == -1) {
          keys[n] = act.room;
          break;
        }
      }
    }
    else {
      /*找到指定钥匙拿走*/
      for (int n = 1; n <= N; n++) {
        if (keys[n] == act.room) {
          keys[n] = -1;
          break;
        }
      }
    }
  }

  for (int n = 1; n < N; n++) {
    cout << keys[n] << " ";
  }
  cout << keys[N] << endl;

  return 0;
}