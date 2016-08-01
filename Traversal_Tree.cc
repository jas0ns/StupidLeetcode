#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  TreeNode(int v): value(v) {
    left = NULL;
    right = NULL;
  }
  int value;
  TreeNode *child;
  TreeNode *brother;
}

int main(int argc, char **argv) {
  int K = 0;
  cin >> K;

  if (K == 0) { cout << -1 << endl;
    return 0;
  }
  // create LCRS Tree
  TreeNode root(1);
  TreeNode *parent = &root;

  int v1, v2;
  for (int i=0; i<(K-1); ++i) {
    bool first = true;
    cin >> v1 >> v2;
    int sibcount = 0;
    while (i == v1) {
      TreeNode *n = new TreeNode(v2);
      if (first) {
        parent->brother = n;
        parent = parent->brother;
        first = false;
      } else {
        parent->right = n;
        parent = parent->brother;
      }
      ++sibcount;
      cin >> v1 >> v2;
    }
    parent = find(v1);
    i += sibcount;
  }
  // Traversal tree according to given leaf sequence 
  vector<int> seq;
  int t = 0;
  while (cin >> t) {
    seq.push_back(t);
    if (cin.get() == '\n') break;
  }

  return 0;
}
