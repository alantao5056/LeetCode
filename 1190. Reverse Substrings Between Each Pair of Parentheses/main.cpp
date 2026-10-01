#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
public:
  string str;
  vector<pii> ints;
  vector<bool> rev;
  vector<int> tox;
  string rec(int x) {
    int a = ints[x].first;
    int b = ints[x].second;

    string res = "";

    if (rev[x]) {
      int i = b-1;
      while (i > a) {
        if (str[i] == ')') {
          res += rec(tox[i]);
          i = ints[tox[i]].first-1;
        } else {
          res += str[i];
          i--;
        }
      }
    } else {
      int i = a+1;
      while (i < b) {
        if (str[i] == '(') {
          res += rec(tox[i]);
          i = ints[tox[i]].second+1;
        } else {
          res += str[i];
          i++;
        }
      }
    }

    return res;
  }

  string reverseParentheses(string s) {
    str = "((" + s + "))";
    int N = str.size();
    tox.resize(N);

    int cnt = -1;
    stack<int> a;
    for (int i = 0; i < N; i++) {
      if (str[i] == '(') {
        ints.push_back({i, -1});
        rev.push_back(false);
        cnt++;
        a.push(cnt);
      }

      tox[i] = cnt;

      if (str[i] == ')') {
        int x = a.top();
        ints[x].second = i; a.pop();
        rev[x] = cnt % 2 == 0;
        cnt--;
      }
    }

    return rec(0);
  }
};

int main() {
  // freopen("0.in", "r", stdin);
  string str; cin >> str;
  Solution s;

  cout << s.reverseParentheses(str) << endl;

  return 0;
}
