#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char**argv) {
  int a = 1, b = 1, c;
  cin >> c;
  if (c <= 0) cout << 0 << endl;

  int x1 = (sqrt(4 * c + 1) - 1) / 2;
  int x2 = -(sqrt(4 * c + 1) - 1) / 2;

  cout << (x1 > 0 ? x1 : x2) << endl;
}
