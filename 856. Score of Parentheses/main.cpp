#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) {
    int N = s.size();

    stack<int> scores;
    scores.push(0);

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        scores.push(0);
      } else {
        int cur = scores.top(); scores.pop();
        int prev = scores.top(); scores.pop();
        if (s[i-1] == '(') {
          scores.push(prev + 1);
        } else {
          scores.push(prev + cur * 2);
        }
      }
    }

    return scores.top();
  }
};

int main() {
  // freopen("0.in", "r", stdin);

  string str; cin >> str;
  Solution s;

  cout << s.scoreOfParentheses(str) << endl;

  return 0;
}
