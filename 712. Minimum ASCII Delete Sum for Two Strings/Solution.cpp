#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string s1, s2;

class Solution {
  public:
    int minimumDeleteSum(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1));
      for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + int(s1[i-1]);
      }

      for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j-1] + int(s2[j-1]);
      }

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (s1[i-1] == s2[j-1]) {
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
          } else {
            dp[i][j] = min(dp[i-1][j] + int(s1[i-1]), min(dp[i][j-1] + int(s2[j-1]), dp[i-1][j-1] + int(s1[i-1]) + int(s2[j-1])));
          }
        }
      }
      return dp[n][m];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> s1 >> s2;

  Solution s;
  cout << s.minimumDeleteSum(s1, s2) << endl;

  return 0;
}