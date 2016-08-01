#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> v;
  bool **d;
  void split(int m, int n, string *s);
  string str;
  int len;
  vector<string> wordBreak(string s, unordered_set<string> &dict);
};

void Solution::split(int m, int n, string *s) {
  if (n == len) {
    s->resize(s->size() - 1);
    v.push_back(*s);
   // cout << *s << endl;
    s->resize(0);
    return;
  }
  for (int i=n; i <= len; ++i) {
    if (d[n][i]) {
      s->append(string(str, m, i-m));
      s->append(" ");
      split(i, i, s);
    }
  }
}

vector <string> Solution::wordBreak(string s, unordered_set<string> &dict) {
  str = s;
  len = s.length();
  if (len == 0 || dict.size() == 0) return v;
  d = new bool*[len+1];
  for (int i=0; i <= len; ++i) {
    d[i] = new bool[len+1];
  }

  for (int i=0; i <= len; ++i) 
    for (int j=0; j <= len; ++j)
      d[i][j] = false;
  
  d[0][0] = true;
  for (int i=0; i < len; ++i) {
    for (int j=0; j < len; ++j) {
      if (d[i][j]) {
        int n = 1;
        for (int k=j; k < len; ++k) {
          if (dict.find(string(str, j, n)) != dict.end()) {
            d[j][k+1] = true;
          }
          ++n;
        }
      }
    }
  }

  for (int i=0; i <= len; ++i) {
    for (int j=0; j <= len; ++j) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }

  d[0][0] = false;
  string *s0 = new string;
  split(0, 0, s0);
  for (int i=0; i <= len; ++i) 
    delete []d[i];
  delete []d;
  return v;
}

int main(int argc, char **argv) {
  Solution s;
  string str("catsanddog");
  unordered_set<string> dict;
  dict.insert(string("cat"));
  dict.insert(string("cats"));
  dict.insert(string("sand"));
  dict.insert(string("and"));
  dict.insert(string("dog"));
  vector<string> v = s.wordBreak(str, dict);
  vector<string>::const_iterator i = v.begin();
  while (i != v.end()) {
    cout << *i << endl;
    ++i;
  }


  return 1;
}
