#include <iostream>

using namespace std;
struct TreeNode { int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
   void flatten(TreeNode* root) {
     if (root != NULL)
       traverse(root);
   }

   TreeNode* traverse(TreeNode* root) {
     if (root == NULL) return NULL;
     TreeNode* l = traverse(root->left);
     TreeNode* r = traverse(root->right);
     if (l == NULL && r == NULL) return root;
     if (l != NULL) {
       l->right = root->right;
       root->right = root->left;
       root->left = NULL;
     }
     return r == NULL ? l : r;
   }
};

int main(int argc, char** argv) {
  Solution s;
  TreeNode n1(1);
  TreeNode n2(2);
  n1.left = &n2;

  s.flatten(&n1);

  cout << n1.right->val << endl;

}
