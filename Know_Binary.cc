#include <iostream>

using namespace std;

class Solution {
public:
  int countBitDiff(int m, int n);
};

int Solution::countBitDiff(int m, int n) {
  int tm = 0, tn = 0, count = 0;
  for (int i=0; i < 32; i++) {
    tm = m;
    tn = n;
    if ((tm & (1 << i)) ^ (tn & (1 << i)))
      ++ count;
  }
  return count;
}

int main(int argc, char **argv) {
  Solution s;
  cout << s.countBitDiff(1999, 2299) << endl;
}
