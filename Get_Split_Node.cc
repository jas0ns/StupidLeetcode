#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int getSplitNode(vector<string> matrix, int indexA, int indexB);
};

int Solution::getSplitNode(vector<string> matrix, int indexA, int indexB) {
  for (int i=0; i < matrix.size(); ++i) {
    for (int j=0; j < i; ++j) {
      matrix[i][j] = '0';
    }
  }
  queue<int> qn;
  vector<int> svn;
  qn.push(0);
  while (!qn.empty()) {
    for (int i=0; i < matrix.size(); ++i)
      if (matrix[qn.front()][i] == '1')
        qn.push(i); 
    svn.push_back(qn.front());
    qn.pop();
  }

  stack<int> sn;
  int pn = indexA;
  for (int i=0; i < matrix.size(); ++i) {
    if (matrix[pn][i] == '1' || matrix[i][pn] == '1') {
      int ipn = 0, ii = 0;
      for (int j=0; j < svn.size(); ++j) {
        if (svn[j] == pn) ipn = j;     
        if (svn[j] == i) ii = j;
      }
      if (ii < ipn) {
        sn.push(i);
        pn = i;
      }
    }
  }
/*
  while (!sn.empty()) {
    cout << sn.top() << endl;
    sn.pop();
  }
*/
  pn = indexB;
  for (int i=0; i < matrix.size(); ++i) {
    if (matrix[pn][i] == '1' || matrix[i][pn] == '1') {
      int ipn = 0, ii = 0;
      for (int j=0; j < svn.size(); ++j) {
        if (svn[j] == pn) ipn = j;     
        if (svn[j] == i) ii = j;
      }
      if (ii < ipn) {
        stack<int> snc = sn;
        while (!snc.empty()) {
          if (i == snc.top())
            return i;
          snc.pop();
        }
        pn = i;
      }
    }
  }

  return 0;
}

int main(int argc, char **argv) {
  Solution s;
  vector<string> matrix;
  matrix.push_back("01011");
  matrix.push_back("10100");
  matrix.push_back("01000");
  matrix.push_back("10000");
  matrix.push_back("10000");
  cout << s.getSplitNode(matrix, 0, 0) << endl;
}
