#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include <stdlib.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head);
};

ListNode *Solution::sortList(ListNode *head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) return head;
  ListNode *pre = NULL;
  ListNode *cur = head;
  ListNode *p, *c, *pmin, *min;
  while (cur != NULL) {
    p = pre;
    c = cur;
    min = cur;
    while (c != NULL) {
      if (c->val <= min->val) {
        min = c;
        pmin = p;
      }
      if (p == NULL) p = cur; 
      else p = p->next;
      c = c->next;
    } 

    if (min == cur) {
      if (pre == NULL) pre = cur;
      else pre = pre->next;
      cur = cur->next;
      continue;
    }
    
    if (pre == NULL) {
      pmin->next = min->next;
      min->next = cur;
      pre = min;
      head = min;
    } else {
      pre->next = min;
      pmin->next = min->next;
      min->next = cur;
      pre = min;
    }
  }

  return head;
}

int main(int argc, char **argv) {
  Solution s;
  ListNode n1(1);
  ListNode n2(3);
  ListNode n3(5);
  ListNode n4(2);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;

  ListNode *p = &n1;
  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }
  
  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }
  cout << "-----------" << endl;
  ListNode *head = s.sortList(&n1);
  p = head;
  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }
}
