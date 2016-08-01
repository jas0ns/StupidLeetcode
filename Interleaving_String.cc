#include <string>
#include <vector>
#include <iostream>

using namespace std;
// DP
class Solution {
 public:
   bool isInterleave(string s1, string s2, string s3) {
     if (s1.length() + s2.length() != s3.length())
       return false;

     vector<vector<bool> > d(s1.length()+1, 
         vector<bool>(s2.length()+1, true));

     for (int i=1; i <= s1.length(); ++i) {
       d[i][0] = d[i-1][0] && s1[i-1] == s3[i-1];
     }

     for (int i=1; i <= s2.length(); ++i) {
       d[0][i] = d[0][i-1] && s2[i-1] == s3[i-1];
     }

     for (int i=1; i <= s1.length(); ++i) {
       for (int j=1; j <= s2.length(); ++j) {
         d[i][j] = (d[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                   d[i][j-1] && s2[j-1] == s3[i+j-1];
       }
     }

     return d[s1.length()][s2.length()];
   }
};

int main(int argc, char** argv) {
  Solution s;
  cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}
/* recursion bad way
class Solution {
 public:
   string str1, str2, str3;
   bool isInterleave(string s1, string s2, string s3) {
     str1 = s1;
     str2 = s2;
     str3 = s3;
     return isil(0 ,0 ,0);
   }
   
   bool isil(int i, int j, int k) {
     if (str1.length() + str2.length() != str3.length())
       return false;
     if (k == str3.length()) {
       return true;
     }

     if (str1[i] == str3[k]) {
       if (isil(i+1, j, k+1)) return true;
       else {
         if (str2[j] == str3[k]) {
           if(isil(i, j+1, k+1)) return true;
           else false;
         } else return false;
       }
     } else if (str2[j] == str3[k]){
       return isil(i, j+1, k+1);
     } else return false;
     return false;
   }
};
*/
