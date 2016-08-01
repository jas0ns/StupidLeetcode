#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode (int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root);
};


vector<int> Solution::postorderTraversal(TreeNode *root) {
  vector<int> v;
  if (root == NULL) return v;
  if (root->left != NULL) {
    vector<int> vl = this->postorderTraversal(root->left);
    for (int i=0; i < vl.size(); ++i)
      v.push_back(vl[i]);
  }
  if (root->right != NULL) {
    vector<int> vr = this->postorderTraversal(root->right);
    for (int i=0; i < vr.size(); ++i)
      v.push_back(vr[i]);
  } 
  v.push_back(root->val);
  return v;
}

int main(int argc, char **argv) {
  Solution s;
  TreeNode n3(3, NULL, NULL);
  TreeNode n2(2, &n3, NULL);
  TreeNode n1(1, NULL, &n2);
  vector<int> v = s.postorderTraversal(&n1);
  for (int i=0; i < v.size(); ++i) {
    cout << v[i] << endl;
  }
}
