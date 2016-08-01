#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool Find(vector<vector<int> > array, int target);
};

bool Solution::Find(vector<vector<int> > array, int target) {
  if (array.size() == 0) return false;
  int i = array.size()-1;
  for (int j=0; j < array[i].size(); ) {
    if (i < 0) break;
    if (array[i][j] == target)
      return true;
    else if (array[i][j] > target)
      --i;
    else
      ++j;
  }
  return false;
}

int main(int argc, char **argv) {
  Solution s;
  vector<vector<int> > array;
  vector<int> a1;
  a1.push_back(2);
  vector<int> a2;
  a2.push_back(3);
  vector<int> a3;
  a3.push_back(5);
  array.push_back(a1);
  array.push_back(a2);
  array.push_back(a3);

  cout << s.Find(array, 6) << endl;
}
