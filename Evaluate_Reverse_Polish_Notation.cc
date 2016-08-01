#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include <stdlib.h>

using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens);
};

int Solution::evalRPN(vector<string> &tokens) {
  stack<int> s;
  vector<string>::const_iterator i = tokens.begin();
  while (i != tokens.end()) {
    string str(*i);
    if ("+" == str || "-" == str ||
        "*" == str || "/" == str) {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      if ("+" == str) 
        s.push(a + b);
      if ("-" == str) 
        s.push(a - b);
      if ("*" == str) 
        s.push(a * b);
      if ("/" == str) 
        s.push(a / b);
    } else {
      s.push(atoi(str.c_str())); 
    }
    ++i;
  }
  return s.top();
}

int main(int argc, char **argv) {
  Solution s;
  vector<string> test;
  test.push_back("10");
  test.push_back("6");
  test.push_back("9");
  test.push_back("3");
  test.push_back("+");
  test.push_back("-11");
  test.push_back("*");
  test.push_back("/");
  test.push_back("*");
  test.push_back("17");
  test.push_back("+");
  test.push_back("5");
  test.push_back("+");
  cout << s.evalRPN(test) << endl;
}
