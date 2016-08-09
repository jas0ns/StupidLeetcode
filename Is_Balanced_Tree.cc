#include <iostream>

using namespace std;

class Solution {
 public:
   bool IsBalanced_Solution(TreeNode* pRoot) {
     if (!pRoot) return true;
     isBalanced(pRoot);
     return result;
   }

   bool result = true;
   int isBalanced(TreeNode* pRoot) {
     if (!result) return 0;
     int l = 0, r = 0;
     if (pRoot->left != NULL)
       l = isBalanced(pRoot->left);
     if (pRoot->right != NULL)
       r = isBalanced(pRoot->right);
     int b = l - r;
     if (b == 0 || b == -1 || b == 1)
       result &= true;
     else result &= false;
     return 1 + max(l, r);
   }
};

int main(int argc, char** argv) {
  Solution s;
}
