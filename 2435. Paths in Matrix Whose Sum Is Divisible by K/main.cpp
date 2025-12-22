#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(k)));

    dp[0][0][grid[0][0]%k] = 1;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (i > 0) {
          for (int l = 0; l < k; l++) {
            int x = (grid[i][j]+l)%k;
            dp[i][j][x] += dp[i-1][j][l];
            dp[i][j][x] %= MOD;
          }
        }
        if (j > 0) {
          for (int l = 0; l < k; l++) {
            int x = (grid[i][j]+l)%k;
            dp[i][j][x] += dp[i][j-1][l];
            dp[i][j][x] %= MOD;
          }
        }
      }
    }

    return dp[N-1][M-1][0];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, M, K; cin >> N >> M >> K;

  vector<vector<int>> grid(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s;
  cout << s.numberOfPaths(grid, K) << endl;

  return 0;
}