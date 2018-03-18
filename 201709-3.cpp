#include <iostream>
#include <map>
#include <string>
#include <cassert>
using namespace std;

/*从str的i位置开始解析字符串*/
string parseString(string &str, int &i) {
  string temp;
  if (str[i] == '"') {
    i++;
  }
  else {
    assert(0);
  }

  while (i < str.size()) {
    /* 出现一个 \ , 跳过并记录下过一个符号*/
    if (str[i] == '\\') {
      i++;
      temp += str[i];
      i++;
    }
    // 结束
    else if (str[i] == '"') {
      break;
    }
    // 中间内容
    else {
      temp += str[i];
      i++;
    }
  }

  if (str[i] == '"') {
    i++;
  }
  else {
    assert(0);
  }

  return temp;
}

void paserObject(string &str, string prefix, map<string, string> &dict, int &i) {
  if (str[i] == '{') {
    i++;
  }
  else {
    assert(0);
  }

  string key, value;
  bool strType = false; // false: key, true: value
  while (i < str.size()) {
    if (str[i] == '"') {
      string temp = parseString(str, i);
      // temp是处理value,仅当处理完value后才保存进map中
      if(strType) {
        value = temp;
        dict[key] = value;
      }
      // temp是处理key
      /*Object 的 prefix 是"", Object中的String的prefix是含.*/
      else {
        key = prefix + (prefix == "" ? "" : ".") + temp;
      }
    }
    // 从key切换到value
    else if (str[i] == ':') {
      strType = true;
      i++;
    }
    // 从value切换到key
    else if (str[i] == ',') {
      strType = false;
      i++;
    }
    else if (str[i] == '{') {
      dict[key] = "";
      paserObject(str, key, dict, i);
    }
    else if (str[i] == '}') {
      break;
    }
    else {
      i++;
    }
  }

  if (str[i] == '}') {
    i++;
  }
  else {
    assert(0);
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  string json;
  if (cin.peek() == '\n') {
    cin.ignore();
  }
  for (int n = 0; n < N; n++) {
    string tmp;
    getline(cin, tmp);
    json += tmp;
  }

  map<string, string> dict;
  int i = 0;
  paserObject(json, "", dict, i);
  string query;
  for (int m = 0; m < M; m++) {
    getline(cin, query);
    // Not found
    if (dict.find(query) == dict.end()) {
      cout << "NOTEXIST" << endl;
    }
    // Found
    else {
      // Object
      if (dict[query] == "") {
        cout << "OBJECT" << endl;
      }
      // String
      else {
        cout << "STRING " << dict[query] << endl;
      }
    }
  }
  return 0;
}