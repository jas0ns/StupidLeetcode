#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
    val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
      if (pRoot1 == NULL || pRoot2 == NULL) return false;
      if(sameTree(pRoot1, pRoot2)) return true;

      bool left = false;
      bool right = false;

      if (pRoot1->left != NULL)
        left = HasSubtree(pRoot1->left, pRoot2);
      if (pRoot1->right != NULL)
        right = HasSubtree(pRoot1->right, pRoot2);
      return left || right;
    }

    bool sameTree(TreeNode* a, TreeNode* b) {
      if (a == NULL && b == NULL) return true;
      if (a == NULL && b != NULL ||
          a != NULL && b == NULL) return false;
      if (a->val == b->val)
        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
      return false;
    }
};

int main(int argc, char **argv) {
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n6(6);
  
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n5.right = &n6;

  TreeNode s1(2);
  TreeNode s2(4);
  TreeNode s3(5);
  TreeNode s4(6);

  s1.left = &s2;
  s1.right = &s3;

  Solution s;
  cout << s.HasSubtree(&n1, &s1) << endl;

}
