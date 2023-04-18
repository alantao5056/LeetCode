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

        if (zero > m || one > n) continue;

        for (int i = m; i >= 0; i--) {
          for (int j = n; j >= 0; j--) {
            if (dp[i][j] == 0) continue;

            // add it
            int newI = i+zero;
            int newJ = j+one;
            if (newI <= m && newJ <= n) {
              dp[newI][newJ] = max(dp[newI][newJ], dp[i][j]+1);
            }
          }
        }

        dp[zero][one] = max(dp[zero][one], 1);
      }

      int result = 0;
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
          result = max(result, dp[i][j]);
        }
      }

      return result;
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