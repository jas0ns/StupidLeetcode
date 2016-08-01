#include <iostream>

using namespace std;

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int l, r, t, b, w, h;
    if (C < E || A > G) return 0;
    if (B > H || D < F) return 0;
    l = A > E ? A - E : E - A;
    r = C > G ? C - G : G - C;
    t = D > H ? D - H : H - D;
    b = B > F ? B - F : F - B;

    return (r - l) * (t - b);
  }
};

int main(int argc, char **argv) {
  Solution s;
  cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9 ,2) << endl;
} 
