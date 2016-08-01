#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode (int v) : val(v), left(NULL), right(NULL) {}
};

struct HW {
  int h;
  int maxDistance;
  HW () : h(0), maxDistance(0) {}
};

HW calc (TreeNode* root) {
  HW lhw, rhw, result;
  if (root->left) lhw = calc(root->left);
  if (root->right) rhw = calc(root->right);
  result.h = max(lhw.h, rhw.h) + 1;
  result.maxDistance = max(lhw.h + rhw.h, max(lhw.maxDistance, rhw.maxDistance));
  return result;
}

int main(int argc, char **argv) {
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n6(6);
  TreeNode n7(7);
  TreeNode n8(8);
  TreeNode n9(9);
  
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.left = &n6;
  n3.right = &n7;
  n4.left = &n8;
  n6.right = &n9;

 cout << calc(&n1).maxDistance << endl;
  
}
