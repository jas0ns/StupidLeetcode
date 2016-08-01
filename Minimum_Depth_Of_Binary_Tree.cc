#include <iostream>
#include <queue>

class Solution {
  public:
    int run(TreeNode *root);
}

int Solution::run(TreeNode *root) {
  if (root == NULL) return 0;

  queue<TreeNode*> q;
  q.push(root);
  int level = 0;
  int cur_num = 1;
  while (cur_num != 0) {
    ++level;
    for (int i=0; i < cur_num; ++i) {
      TreeNode *t = q.front();
      if (t->left == NULL &&
          t->right == NULL) {
        return level;
      }
      if (t->left != NULL) q.push(t->left);
      if (t->right != NULL) q.push(t->right);
      q.pop();
    }
    cur_num = q.size();
  }
  return level;
}

int main(int argcc char **argv) {
  
}
