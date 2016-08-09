#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
   int MoreThanHalfNum_Solution(vector<int> numbers) {
     if (numbers.size() == 0) return 0;
     if (numbers.size() == 1) return numbers[0];
     int count = 1;
     int cur = numbers[0];
     for (int i=1; i<numbers.size(); ++i) {
       if (count == 0) {
         cur = numbers[i];
         count = 1;
         continue;
       }
       if (cur == numbers[i])
         ++count;
       else {
         --count;
       }
     }
     if (count == 0) return 0;

     int c = 0;
     for (int i=0; i<numbers.size(); ++i) {
       if (numbers[i] == cur) ++c;
     }
     if (c >= numbers.size() / 2)
       return cur;
     else return 0;
   }
};

int main(int argc, char** argv) {
  Solution s;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(5);
  v.push_back(4);
  v.push_back(2);
  cout << s.MoreThanHalfNum_Solution(v) << endl;
}

