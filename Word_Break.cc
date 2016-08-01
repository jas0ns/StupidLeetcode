#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict);
};

bool Solution::wordBreak(string s, unordered_set<string> &dict) {
  int len = s.length();
  if (len == 0 || dict.size() == 0) return false;
  bool *d = new bool[len+1];

  for (int i=0; i <= len; ++i) 
    d[i] = false;
  
  d[0] = true;
  for (int i=0; i < len; ++i) {
    if (d[i]) {
      int k = 1;
      for (int j=i; j < len; ++j) {
        if (dict.find(string(s, i, k)) != dict.end()) {
          d[j+1] = true;
        }
        ++k;
      }
    }
  }
  bool ret = d[len];
  delete[] d;
  return ret;
}

int main(int argc, char **argv) {
  Solution s;
  string str("Ilikeamotorbike");
  unordered_set<string> dict;
  dict.insert(string("I"));
  dict.insert(string("like"));
  dict.insert(string("a"));
  dict.insert(string("moto"));
  dict.insert(string("bike"));
  cout << s.wordBreak(str, dict) << endl;

}
