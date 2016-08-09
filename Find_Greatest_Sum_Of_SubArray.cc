#include <iostream>

using namespace std;

class Solution {
 public:
   int FindGreatestSumOfSubArray(vector<int> array) {
     if (array.size() == 0) return 0;
     int m = array[0];
     int d = array[0];

     for (int i=1; i<array.size(); ++i) {
       d = max(d + array[i], array[i]);
       m = max(m, d);
     }
     return m;
   }
};

int main(int argc, char** argv) {
  Solution s;
}
