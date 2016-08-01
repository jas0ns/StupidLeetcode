#include <iostream>
#include <stack>
#include <set>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// best solution with recursion
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
  }
};
/*
class Solution {
 public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
     if (root == p || root == q) return root;
     stack<TreeNode*> s1, s2;
     s1.push(root);
     s2.push(root);
     TreeNode *cur1 = root, *cur2 = root;
     set<TreeNode*> dup;
     while (cur1 != p) {
       if (cur1->left != NULL && dup.find(cur1->left) == dup.end()) {
         cur1 = cur1->left;
         s1.push(cur1);
         dup.insert(cur1);
       } else if (cur1->right != NULL && dup.find(cur1->right) == dup.end()){
         cur1 = cur1->right;
         s1.push(cur1);
         dup.insert(cur1);
       } else {
         s1.pop();
         cur1 = s1.top();
       }
     } 

     dup.clear();
     while (cur2 != q) {
       if (cur2->left != NULL && dup.find(cur2->left) == dup.end()) {
         cur2 = cur2->left;
         s2.push(cur2);
         dup.insert(cur2);
       } else if (cur2->right != NULL && dup.find(cur2->right) == dup.end()){
         cur2 = cur2->right;
         s2.push(cur2);
         dup.insert(cur2);
       } else {
         s2.pop();
         cur2 = s2.top();
       }
     } 

     while (s1.size() > s2.size()) { s1.pop(); }
     while (s2.size() > s1.size()) { s2.pop(); }

     while (s1.top() != s2.top()) {
       s1.pop();
       s2.pop();
     }

     return s1.top();
   }
};
*/

/* stupid recursion way
class Solution {
 public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (root == p || root == q) return root;
     bool l = inTree(root->left, p);
     bool r = inTree(root->right, q);
     if (! (l ^ r))
       return root;
     if (l == true && r == false)
       return lowestCommonAncestor(root->left, p, q);
     if (l == false && r == true)
       return lowestCommonAncestor(root->right, p, q);
     return NULL;
   }

   bool inTree(TreeNode* root, TreeNode* t) {
     if (root == NULL) return false;
     if (root == t) return true;
     return inTree(root->left, t) || inTree(root->right, t);
   }
};
*/
int main(int argc, char** argv) {
  Solution s;
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n6(6);
  TreeNode n7(7);
  TreeNode n8(8);
  
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.left = &n6;
  n5.left = &n7;
  n5.right = &n8;

  cout << s.lowestCommonAncestor(&n1, &n7, &n6)->val << endl;
}
