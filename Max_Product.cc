#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      vector<int> maxd;
      vector<int> mind;
      if (nums.size() == 0) return 0;
      maxd.push_back(nums[0]);
      mind.push_back(nums[0]);
      for (int i=1; i < nums.size(); ++i) {
        maxd.push_back(max(nums[i], max(maxd[i-1] * nums[i], mind[i-1] * nums[i])));
        mind.push_back(min(nums[i], min(maxd[i-1] * nums[i], mind[i-1] * nums[i])));
      }
      return *max_element(maxd.begin(), maxd.end());
    }
};

int main(int argc, char **argv) {
  Solution s;
  vector<int> v;
  v.push_back(2); 
  v.push_back(3); 
  v.push_back(-2); 
  v.push_back(4); 
  cout << s.maxProduct(v) << endl;
  return 1;
}
