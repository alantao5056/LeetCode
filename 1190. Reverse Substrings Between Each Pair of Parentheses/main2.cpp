#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string reverseParentheses(string s) {
    int N = s.size();

    stack<int> start;
    vector<int> next(N);
    for (int i = 0; i < N; i++) {
      if (s[i] == '(') {
        start.push(i);
      } else if (s[i] == ')') {
        int j = start.top(); start.pop();

        next[j] = i;
        next[i] = j;
      }
    }

    bool v = true;
    int i = 0;
    string res = "";
    while (i < N && i >= 0) {
      if (s[i] == '(' || s[i] == ')') {
        if (v) {
          i = next[i]-1;
        } else {
          i = next[i]+1;
        }
        v = !v;
      } else {
        res += s[i];
        if (v) i++;
        else i--;
      }
    }

    return res;
  }
};

int main() {
  // freopen("0.in", "r", stdin);
  string str; cin >> str;

  Solution s;

  cout << s.reverseParentheses(str) << endl;

  return 0;
}
