#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* ph = nullptr;
        ListNode* h = head;
        bool first = true;
        while (true) {
            ListNode* cur = h;
            bool flag = false;
            for (int i = 0; i < k; i++) {
                if (cur == nullptr) {
                    flag = true;
                    break;
                }
                cur = cur->next;
            }

            if (flag) break;

            ListNode* prev = h;
            cur = h->next;
            ListNode* nh = nullptr;
            for (int i = 1; i < k; i++) {
                ListNode* next = cur->next;
                cur->next = prev;
                if (i == k-1) {
                  // last node which is going to be first node
                  nh = next;
                  // get new return
                  if (first) {
                    head = cur;
                    first = false;
                  }
                  if (ph != nullptr) {
                    ph->next = cur;
                  }

                  continue;
                }
                prev = cur;
                cur = next;
            }
            
            ph = h;
            h = nh;
        }

        if (ph != nullptr) {
          ph->next = h;
        }

        return head;
    }
};


int main() {
  ListNode one(1);
  ListNode two(2);
  // ListNode three(3);
  // ListNode four(4);
  // ListNode five(5);

  one.next = &two;
  // two.next = &three;
  // three.next = &four;
  // four.next = &five;

  int k = 2;
  Solution s;
  s.reverseKGroup(&one, k);

  return 0;
}