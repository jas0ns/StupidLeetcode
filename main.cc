#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int N = 0, result = 1;
  cin >> N;

  result = 1 << N;

  cout << hex << result << endl;

  return 0;
}
