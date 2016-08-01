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
  ListNode *detectCycle(ListNode *head);
}; 

ListNode *Solution::detectCycle(ListNode *head) {
  if (head == NULL || head->next == NULL) return NULL;
  ListNode *slow, *fast;
  slow = head;
  fast = head;
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      fast = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return fast;
    }
  }
  return NULL;
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
  n6.next = &n3;
  
  cout << s.detectCycle(&n1)->val << endl;
}
