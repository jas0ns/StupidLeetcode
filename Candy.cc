#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candies;
    if (ratings.size() == 0) return 0;
    if (ratings.szie() == 1) return 1;
    candies.push_back(1);
    int p = 0;
    for (int i=1; i<ratings.size(); ++i) {
      if (ratings[p] < ratings[i])
        candies.push_back(p+1);
      else if (ratings[p] > ratings[i]) {
        for (int j=i; j>=0; --j) {
          if (candies[j])
        }
        if (p == 1) {
          ++candies[i-1];
          candies.push_back();
        }
        else
          candies.push_back(1);
      } else
        candies.push_back(p);
      ++p;
    }
  }
};

int main(int argc, char **argv) {
  Solution s;
}
