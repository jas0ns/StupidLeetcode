#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void replaceSpace(char *str, int length);
};

void Solution::replaceSpace(char *str, int length) {
  if (str == NULL || length == 0) return;
  for (int i=0; i<length; ++i) {
    if (str[i] == ' ') {
      for (int j=length-1; j>i; --j) {
        str[j+2] = str[j]; 
      }
      str[i] = '%';
      str[i+1] = '2';
      str[i+2] = '0';
      i += 2;
      length += 3;
    }
  }
}

int main(int argc, char **argv) {
  Solution s;
  char str[] = "what the fuck";
  s.replaceSpace(str, 13);
  cout << string(str) << endl;
}
