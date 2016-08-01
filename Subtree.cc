#include <iostream>

struct tnode {
  int value;
  tnode *left;
  tnode *right;
};

bool subtree(tnode *t1, tnode *t2) {
  if (t1->value == t2->value) {
    subtree(t1.left == t2->left)  
  }
  subtree(t1.left, t2);
  subtree(t1.right, t2);
}

bool sametree(tnode *t1, tnode *t2) {
}

int main(int argc, char **argv) {
   
}
