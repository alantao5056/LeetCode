#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int M, N, maxMove, startRow, startColumn;

class Solution {
  public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      if (maxMove == 0) return 0;
      vector<int> i_ = {0, -1, 0, 1};
      vector<int> j_ = {1, 0, -1, 0};
      int MOD = 1000000007;
      vector<vector<vector<int>>> dp(m+2, vector<vector<int>>(n+2, vector<int>(maxMove)));
      dp[startRow+1][startColumn+1][0] = 1;
      for (int s = 1; s < maxMove; s++) {
        for (int i = 1; i <= m; i++) {
          for (int j = 1; j <= n; j++) {
            // dp[i][j][s]=dp[i][j][s-1];
            for (int k = 0; k < 4; k++) {
              dp[i][j][s] += dp[i+i_[k]][j+j_[k]][s-1];
              dp[i][j][s] %= MOD;
            }
          }
        }
      }

      int result = 0;
      for (int j = 1; j <= n; j++) {
        for (int s = 0; s < maxMove; s++) {
          result += dp[1][j][s];
          result %= MOD;
          result += dp[m][j][s];
          result %= MOD;
        }
      }

      for (int i = 1; i <= m; i++) {
        for (int s = 0; s < maxMove; s++) {
          result += dp[i][1][s];
          result %= MOD;
          result += dp[i][n][s];
          result %= MOD;
        }
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> M >> N >> maxMove >> startRow >> startColumn;

  Solution s;
  cout << s.findPaths(M, N, maxMove, startRow, startColumn) << endl;


  return 0;
}