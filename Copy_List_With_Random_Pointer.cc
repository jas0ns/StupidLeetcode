#include <iostream>

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *cur = head;
    while (cur != NULL) {
      RandomListNode *n = new RandomListNode(cur->label);
      n->next = cur->next;
      n->random = cur->random;
      cur->next = n;
      cur = n->next;
    } 

    cur = head->next;
    while(cur != NULL) {
      if (cur->random) {
        cur->random = cur->random->next;
      }
      if (!cur->next) break;
      cur = cur->next->next;
    }

    RandomListNode *newhead = head->next;
    RandomListNode *t;
    cur = head;
    while(cur != NULL) {
      if (!cur->next) break;
      t = cur->next;
      cur->next = t->next;
      cur = t;
    }

    return newhead;
  }
};


int main(int argc, char **argv) {
  RandomListNode n1(1);
  RandomListNode n2(2);
  RandomListNode n3(3);
  RandomListNode n4(4);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n2.random = &n3;
  n3.random = &n1;
  n4.random = &n4;
  
  Solution s;
  RandomListNode *n = s.copyRandomList(&n1);
  cout << n->next->next->next->random->label << endl;

  return 0;
}
