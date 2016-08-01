#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int>::iterator pi;
struct TreeNode* reConstruct(vector<int> in) {
  if (in.size() == 0) return NULL;
  TreeNode *root = new TreeNode(*pi);
  ++pi;
  if(in.size() == 1) return root;

  vector<int>::iterator vi = find(in.begin(), in.end(), root->val);

  if (in.begin() != vi) {
    vector<int> subinleft(in.begin(), vi);
    root->left = reConstruct(subinleft);
  }

  vector<int> subinright(vi + 1, in.end());
  root->right = reConstruct(subinright);

  return root;
}

class Solution {
public:
  struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
    pi = pre.begin();
    return reConstruct(in);
  }
};


int main(int argc, char **argv) {
  Solution s;
  vector<int> pre;
  vector<int> in;
  pre.push_back(1);
  pre.push_back(2);
  pre.push_back(4);
  pre.push_back(7);
  pre.push_back(3);
  pre.push_back(5);
  pre.push_back(6);
  pre.push_back(8);

  in.push_back(4);
  in.push_back(7);
  in.push_back(2);
  in.push_back(1);
  in.push_back(5);
  in.push_back(3);
  in.push_back(8);
  in.push_back(6);

  TreeNode *t = s.reConstructBinaryTree(pre, in);
  
  return 1;
}
