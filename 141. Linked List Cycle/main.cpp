#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  set<ListNode*> visited;
  bool hasCycle(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr) {
      if (visited.find(cur) != visited.end()) {
        return true;
      }
      
      visited.insert(cur);
      cur = cur->next;
    }

    return false;
  }
};
int main() {
  ListNode root(-1);
  // ListNode one(2);
  // ListNode two(0);
  // ListNode three(-4);

  // root.next = &one;
  // one.next = &two;
  // two.next = &three;
  // three.next = &one;

  Solution s;

  cout << s.hasCycle(&root) << endl;

  return 0;
}