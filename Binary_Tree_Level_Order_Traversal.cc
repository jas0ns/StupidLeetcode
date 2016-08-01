#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static void printVector(vector<int> v) {
  for (int i=0; i<v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

class Solution {
public:
 vector<vector<int>> levelOrder(TreeNode* root) {
   vector<vector<int>> result;
   if (!root) return result;
   queue<TreeNode*> q;
   q.push(root);

   vector<TreeNode*> nextLevel;
   while (!q.empty()) {
     vector<int> v;
     while (!q.empty()) {
       TreeNode *front = q.front();
       v.push_back(front->val);
       if (front->left != NULL) {
         nextLevel.push_back(front->left);
       }
       if (front->right != NULL) {
         nextLevel.push_back(front->right);
       }
       q.pop();
     }

     result.push_back(v);
     
     for (int i=0; i < nextLevel.size(); ++i) {
       q.push(nextLevel[i]);
     }
     nextLevel.clear();
   }

   return result;
 }
};

int main(int argc, char **argv) {
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
  n6.left = &n7;
  n6.right = &n8;

  vector<vector<int>> result = s.levelOrder(&n1);

  for (int i=0; i<result.size(); ++i) {
    for (int j=0; j<result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;

}
