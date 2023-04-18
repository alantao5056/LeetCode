#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();
      if (n == 1) {
        return matrix[0][0];
      }
      vector<vector<int>> dp(n+2, vector<int>(n+2, INT_MAX));
      int result = INT_MAX;
      for (int i = 1; i <= n; i++) {
        dp[1][i] = matrix[0][i-1];
      }
      for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1])) + matrix[i-1][j-1];
          if (i == n) { // last row
            result = min(result, dp[i][j]);
          }
        }
      }
      
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<vector<int>> matrix(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }

  Solution s;
  cout << s.minFallingPathSum(matrix) << endl;

  return 0;
}