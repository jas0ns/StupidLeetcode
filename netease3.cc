#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char**argv) {
  int n = 0, m = 0;
  cin >> n >> m;
  string s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;
  
  int m1 = s1[0];
  int m2 = s1[0];
  for (int i=0; i<s1.length(); ++i) {
    m2 = m1;
    m1 = min(m1, s1[i] - '0');
  }
  for (int i=0; i<s2.length(); ++i) {
    m2 = m1;
    m1 = min(m1, s2[i] - '0');
  }
  for (int i=0; i<s3.length(); ++i) {
    m2 = m1;
    m1 = min(m1, s3[i] - '0');
  }
  for (int i=0; i<s4.length(); ++i) {
    m2 = m1;
    m1 = min(m1, s4[i] - '0');
  }

  cout << m2 << endl;
}
