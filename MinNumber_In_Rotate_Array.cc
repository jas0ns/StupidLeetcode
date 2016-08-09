#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int minNumberInRotateArray(vector<int> v) {
    int l = 0, h = v.size() - 1;
    int m = 0;
    while (l < h) {
      m = l + (h - l)/2;
      if (v[h] > v[m]) {
        h = m;
      } else if (v[h] < v[m]){
        l = m + 1; 
      } else
        --h;
    }
    return v[l];
  }
};

int main(int argc, char **argv) {
  Solution s;
  int a[] = {2, 3, 4, 5, 1, 2,2,2,2,2,2,2};
  vector<int> v;
  for (int i=0; i < 12; i++) {
    v.push_back(a[i]);
  }
  cout << s.minNumberInRotateArray(v) << endl;
  return 1;
}

