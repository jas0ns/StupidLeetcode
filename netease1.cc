#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char**argv) {
  int n = 0, c;
  int sum = 0;
  cin >> n;
  if (n <= 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> v;
  for (int i=0; i<n; ++i) {
    cin >> c;
    sum += c;
    v.push_back(c);
  }

  if (sum % n != 0) {
    cout << -1 << endl;
    return 0;
  }
  int avg = sum / n;
  
  int count = 0;
  for (int i=0; i<n; ++i) {
    if (((v[i]-avg)) % 2 != 0) {
      cout << -1 << endl;
      return 0;
    } 
    count += v[i] > avg ? (v[i]-avg) / 2 : 0;
  }

  cout << count << endl;
    
}
