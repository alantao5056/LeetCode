#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<vector<int>> dp(m+1, vector<int>(n+1));

      for (int s = 0; s < strs.size(); s++) {
        int zero = 0;
        int one = 0;
        for (int k = 0; k < strs[s].size(); k++) {
          if (strs[s][k] == '0') {
            zero++;
          } else {
            one++;
          }
        }

        dp[zero][one] = max(dp[zero][one], 1);
        for (int i = zero; i <= m; i++) {
          for (int j = one; j <= n; j++) {
            int needZero = i-zero;
            int needOne = j-one;
            if (dp[needZero][needOne] != 0) {
              dp[i][j] = max(dp[i][j], 1 + dp[needZero][needOne]);
            }
          }
        }
      }
      return dp[m][n];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  int m, n;
  cin >> m >> n;
  vector<string> strs(N);
  for (int i = 0; i < N; i++) {
    cin >> strs[i];
  }

  Solution s;
  cout << s.findMaxForm(strs, m, n) << endl;

  return 0;
}