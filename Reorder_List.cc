#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode *head);
};

void Solution::reorderList(ListNode *head) {
  if (head == NULL) return;
  if (head->next == NULL) return;
  if (head->next->next == NULL) return;
  
  stack<ListNode*> q;
  ListNode *pre, *cur;
  cur = head;
  while (cur != NULL) {
    q.push(cur);
    cur = cur->next;
  }
  
  cur = head->next;
  pre = head;
  while (cur != NULL) {
    if (cur->next == NULL) break;
    ListNode *tail = q.top();
    q.pop();
    ListNode *ptail = q.top();
    ptail->next = NULL;
    tail->next = cur;
    pre->next = tail;
    pre = cur;
    if (cur->next == NULL) break;
    cur = cur->next;
  }
}

int main(int argc, char **argv) {
  Solution s;
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode n6(6);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;
  
  s.reorderList(&n1);
  ListNode *cur = &n1;
  while (cur != NULL) {
    cout << cur->val << endl;
    cur = cur->next;
  }
}
