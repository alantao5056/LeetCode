#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    s = " " + s;
    t = " " + t;

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i-1][j];
        if (s[i] != t[j]) continue;

        dp[i][j] += dp[i-1][j-1];
      }
    }

    return dp[n][m];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s, t; cin >> s >> t;

  Solution sol;
  cout << sol.numDistinct(s, t) << endl;

  return 0;
}