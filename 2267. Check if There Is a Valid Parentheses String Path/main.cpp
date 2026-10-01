#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool hasValidPath(vector<vector<char>>& grid) {
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(M+1, vector<bool>(101)));

    dp[0][1][0] = true;

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (grid[i-1][j-1] == '(') {
          for (int k = 1; k <= 100; k++) {
            dp[i][j][k] = dp[i-1][j][k-1] || dp[i][j-1][k-1];
          }
        } else {
          for (int k = 0; k < 100; k++) {
            dp[i][j][k] = dp[i-1][j][k+1] || dp[i][j-1][k+1];
          }
        }
      }
    }

    return dp[N][M][0];
  }
};

int main() {
  // freopen("0.in", "r", stdin);
  int N, M;

  cin >> N >> M;
  vector<vector<char>> grid(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s;
  cout << s.hasValidPath(grid) << endl;

  return 0;
}
