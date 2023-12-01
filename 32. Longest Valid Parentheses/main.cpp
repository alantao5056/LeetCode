#include <bits/stdc++.h>

class Solution {
  public: int longestValidParentheses(string s) {
    int n = s.length();
    stack<int> left;
    int result = 0;
    int cur = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        left.push(i);
      } else {
        if (left.size() > 0) {
          left.pop();
          cur++;
        } else {
          // overadressed
          result = max(result, cur * 2);
          cur = 0;
          last = i;
        }
      }
    }

    if (left.size() == 0) {
      result = max(result, cur * 2);
    } else {
      int prev = n;
      while (left.size() != 0) {
        int cur = left.top();
        left.pop();
        result = max(result, prev - cur - 1);
        prev = cur;
      }
      result = max(result, prev - last - 1);
    }

    return result;
  }
};