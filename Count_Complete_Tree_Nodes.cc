#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    int ll = 0, rl = 0;
    while(l) { ++ll; l = l->left; }
    while(r) { ++rl; r = r->left; }
    if (ll == rl) return (1 << ll) + countNodes(rl-1, root->right);
    return (1 << rl) + countNodes(ll-1, root->left);
  }

  int countNodes(int ll, TreeNode* root) {
    if (!root) return 0;
    TreeNode* r = root->right;
    int rl = 0;
    while(r) { ++rl; r = r->left; }
    if (ll == rl) return (1 << ll) + countNodes(rl-1, root->right);
    return (1 << rl) + countNodes(ll-1, root->left);
  }
};

int main(int argc, char **argv) {
  return 1;
}
