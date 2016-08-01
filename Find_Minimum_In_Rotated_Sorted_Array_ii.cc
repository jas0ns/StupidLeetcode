#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &num) {
      int lo = 0;
      int hi = num.size() - 1;
      int mid = 0;

      while(lo < hi) {
        mid = lo + (hi - lo) / 2;

        if (num[mid] > num[hi]) {
          lo = mid + 1;
        }
        else if (num[mid] < num[hi]) {
          hi = mid;
        }
        else { // when num[mid] and num[hi] are same
          hi--;
        }
      }
      return num[lo];
    }
};


int main(int argc, char **argv) {
  Solution s;
  vector<int> v;
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);

  cout << s.findMin(v) << endl;
}
