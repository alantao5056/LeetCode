#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
  public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      if (obstacleGrid[i][0]) break;
      dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
      if (obstacleGrid[0][i]) break;
      dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j]) continue;

        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }

    return dp[m-1][n-1];
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int m, n;
  cin >> m >> n;
  vector<vector<int>> obstacles(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> obstacles[i][j];
    }
  }

  Solution s;
  cout << s.uniquePathsWithObstacles(obstacles) << endl;


  return 0;
}