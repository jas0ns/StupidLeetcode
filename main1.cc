#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  string in;
  
  while(getline(cin, in)) {
    int count = 0;
    for (int i=0; i<in.length(); ++i) {
      if (in[i] == 'A') break; 
      if (in[i] == '(') {
        ++count;
      } else if (in[i] == ')') {
        --count;
      }
    }
    cout << count << endl;
  }

  return 0;
}
