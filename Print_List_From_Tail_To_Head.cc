#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> printListFromTailToHead(struct ListNode* head);
};

vector<int> Solution::printListFromTailToHead(struct ListNode* head) {
  vector<int> v;
  stack<ListNode*> s;
  if (head == NULL) return v;
  s.push(head);
  while (s.top()->next != NULL) {
    s.push(s.top()->next);
  }

  while(!s.empty()) {
    v.push_back(s.top()->val);
    s.pop();
  }

  return v;
}

int main(int argc, char **argv) {
  Solution s;
  ListNode head(1);
  head.next = new ListNode(2);
  head.next->next = new ListNode(3);
  vector<int> v = s.printListFromTailToHead(&head);
  vector<int>::const_iterator i = v.begin();
  while (i != v.end()) {
    cout << *i << endl;
    ++i;
  }
}
