#include <iostream>
#include <vector>

using namespace std;
// partition
class Solution {
 public:
   vector<int> input;
   int k;
   vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
     vector<int> v;
     if (input.size() == 0 || k == 0 || k > input.size()) return v;
     this->input = input; this->k = k;
     adjust(0, input.size() - 1);
     for (int i=0; i<k; ++i) {
       v.push_back(this->input[i]);
     }
     return v;
   }

   void adjust(int l, int h) {
     if (l == h) return;
     int pl = l, ph = h;
     int m = l;
     int t;
     if (++l == h) {
       if (input[m] > input[h]) {
         t = input[h];
         input[h] = input[m];
         input[m] = t;
         m = h;
       }
       return;
     }
     while (l != h) {
       if (h != m) {
         if (input[h] <= input[m]) {
           t = input[h];
           input[h] = input[m];
           input[m] = t;
           m = h;
         } else --h;
       } else {
         if (input[l] > input[m]) {
           t = input[l];
           input[l] = input[m];
           input[m] = t;
           m = l;
         } else ++l;
       }
     }
     
     if (m == k-1) return;
     else if (m > k-1) adjust(pl, m-1);
     else adjust(m+1, ph);
   }
};

int main(int argc, char** argv) {
  Solution s;
  vector<int> v;
  v.push_back(4);
  v.push_back(5);
  v.push_back(1);
  v.push_back(6);
  v.push_back(2);
  v.push_back(7);
  v.push_back(3);
  v.push_back(8);
  vector<int> out = s.GetLeastNumbers_Solution(v, 5);

  for (int i=0; i<out.size(); ++i) {
    cout << out[i] << endl;
  }
}
