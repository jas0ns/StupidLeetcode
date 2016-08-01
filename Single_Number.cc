#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int singleNumber(int A[], int n) {
      int m = 0, i = 0, j = n-1, t;
      if (n == 1) return A[0];
      while (i != j) {
        if (j != m) {
          if (A[j] <= A[m]) {
            t = A[j];
            A[j] = A[m];
            A[m] = t;
            m = j;
          } else --j;
        } else {
          if (A[i] > A[m]) {
            t = A[i];
            A[i] = A[m];
            A[m] = t;
            m = i;
          } else ++i;
        }
      }
      if (i % 2 == 0) 
        return singleNumber(A, i+1);
      else
        return singleNumber(A+i+1, n-i-1);
    }
};

int main(int argc, char **argv) {
  Solution s;
  int A[] = {2, 3, 4, 2, 1, 3, 5, 5, 4, 1, 9 ,11, 9};
  s.singleNumber(A, 13);
  cout << s.singleNumber(A, 13) << endl;
}
