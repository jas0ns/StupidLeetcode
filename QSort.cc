#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void qsort(int *A, int n) {
      int m = 0, i = 0, j = n-1, t;
      if (n <= 1) return;
      if (n == 2) {
        if (A[0] > A[1]){
          t = A[0];
          A[0] = A[1];
          A[1] = t;
        }
        return;
      }
      while (i != j) {
        if (j != m) {
          if (A[j] < A[m]) {
            t = A[j];
            A[j] = A[m];
            A[m] = t;
            m = j;
          } else --j;
        } else {
          if (A[i] >= A[m]) {
            t = A[i];
            A[i] = A[m];
            A[m] = t;
            m = i;
          } else ++i;
        }
      }
      qsort(A, i);
      qsort(A+i+1, n-i-1);
    }
};

int main(int argc, char **argv) {
  Solution s;
  int A[] = {2, 3, 4, 2, 3, 5, 5, 4, 1, 9 ,11, 9};
  s.qsort(A, 12);
  for (int i=0; i < 12; ++i) {
    cout << A[i] << " ";
  }
}
