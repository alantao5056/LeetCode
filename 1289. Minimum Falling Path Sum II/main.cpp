#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
      for (int i = 0; i < n; i++) {
        dp[0][i] = grid[0][i];
      }

      for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            if (k == j) continue;
            dp[i][j] = min(dp[i][j], dp[i-1][k]+grid[i][j]);
          }
        }
      }
      
      int result = INT_MAX;
      for (int i = 0; i < n; i++) {
        result = min(result, dp[n-1][i]);
      }
      return result;
    }
};

int N;

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<vector<int>> grid(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s;
  cout << s.minFallingPathSum(grid) << endl;

  return 0;
}