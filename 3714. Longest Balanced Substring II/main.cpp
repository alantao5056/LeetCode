#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
  int solve1(string s) {
    int ans = 1;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i-1]) {
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }

    return max(ans, cnt);
  }

  int solve2(string s, char c1, char c2) {
    map<int, int> diffs; // diff, pos
    diffs[0] = -1;
    int cnt1 = 0;
    int cnt2 = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c1 || s[i] == c2) {
        if (s[i] == c1) {
          cnt1++;
        } else {
          cnt2++;
        }

        int diff = cnt2-cnt1;

        if (diffs.find(diff) != diffs.end()) {
          ans = max(ans, i-diffs[diff]);
        } else {
          diffs[diff] = i;
        }
      } else {
        cnt1 = 0;
        cnt2 = 0;
        diffs.clear();
        diffs[0] = i;
      }
    }

    return ans;
  }

  int solve3(string s) {
    map<pii, int> diffs; // diff, pos
    diffs[{0, 0}] = -1;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a') {
        cnt1++;
      } else if (s[i] == 'b') {
        cnt2++;
      } else {
        cnt3++;
      }

      int diff1 = cnt2-cnt1;
      int diff2 = cnt3-cnt1;
      pii dp = {diff1, diff2};

      if (diffs.find(dp) != diffs.end()) {
        ans = max(ans, i-diffs[dp]);
      } else {
        diffs[dp] = i;
      }
    }

    return ans;
  }

public:
  int longestBalanced(string s) {
    int N = s.size();

    vector<int> answers = {solve1(s), solve2(s, 'a', 'b'), solve2(s, 'a', 'c'), solve2(s, 'b', 'c'), solve3(s)};
    int ans = 0;
    for (int i = 0; i < answers.size(); i++) {
      ans = max(ans, answers[i]);
    }

    return ans;
  }
};

int main() {
  // freopen("0.in", "r", stdin);

  string s; cin >> s;

  Solution sol;
  cout << sol.longestBalanced(s) << endl;
  
  return 0;
}
