#include <iostream>
#include <vector>

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

ListNode* Solution::sortList(ListNode *head) {
  if (head == NULL) return head;
  ListNode *left = head;
  ListNode *fast = head;
  ListNode *slow = head;
  ListNode *preslow = NULL;
  while (fast != NULL) {
    if (fast->next == NULL) break;
    if (preslow == NULL) preslow = head;
    else preslow = preslow->next;
    slow = slow->next;
    fast = fast->next->next;
  }
  //if (fast->next != NULL) slow = slow->next;
  ListNode *right = slow;
  if (left->next == right && right->next == NULL) {
    if (left->val > right->val) {
      right->next = left;
      left->next = NULL;
      return right;
    } else return left;
  } else if (left == right) return left;

  preslow->next = NULL;
  ListNode *l = this->sortList(left);
  ListNode *r = this->sortList(right);
  ListNode *i, *j, *ci, *pj = NULL;
 
  for (i = r; i != NULL; ) {
    ci = i;
    i = i->next;
    pj = NULL;
    for (j = l; j != NULL; j = j->next) {
      if (ci->val < j->val) {
        if (j == l) {
          ci->next = j;
          l = ci;
        } else {
          ci->next = j;
          pj->next = ci;
        }
        break;
      } else {
        if (pj == NULL) pj = j;
        else pj = pj->next;

        if (j->next == NULL) {
          j->next = ci;
          return l;
        }
      }
    }
  }
  return l;
}

int main(int argc, char **argv) {
  Solution s;
  ListNode n1(5);
  ListNode n2(2);
  ListNode n3(1);
  ListNode n4(4);
  ListNode n5(12);
  ListNode n6(9);
  ListNode n7(100);
  ListNode n8(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;
  n6.next = &n7;
  n7.next = &n8;


  ListNode *cur = &n1;
  while (cur != NULL) {
    cout << cur->val << endl;
    cur = cur->next;
  }

  cout << "--------------" << endl;

  ListNode *head = s.sortList(&n1);
  cur = head;
  while (cur != NULL) {
    cout << cur->val << endl;
    cur = cur->next;
  }
}
