#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            if (matrix[i-1][j-1] == '0') continue;
            dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            ans = max(ans, dp[i][j]);
          }
        }

        return ans*ans;
    }
};


int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);


  int N, M;
  cin >> N >> M;

  vector<vector<char>> matrix(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> matrix[i][j];
    }
  }

  Solution s;

  s.maximalSquare(matrix);
  return 0;
}