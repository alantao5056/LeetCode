#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int maxDistance(vector<vector<int>>& grid) {
      int n = grid.size();

      vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
      bool land = false;
      bool water = false;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j]) {
            dp[i][j] = 0;
            land = true;
          } else {
            water = true;
          }
        }
      }

      if (!land || !water) {
        return -1;
      }

      for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            if (dp[j][k] != i) continue;

            if (j != n-1 && dp[j+1][k] == INT_MAX) {
              dp[j+1][k] = i+1;
            }
            if (j != 0 && dp[j-1][k] == INT_MAX) {
              dp[j-1][k] = i+1;
            }
            if (k != n-1 && dp[j][k+1] == INT_MAX) {
              dp[j][k+1] = i+1;
            }
            if (k != 0 && dp[j][k-1] == INT_MAX) {
              dp[j][k-1] = i+1;
            }
          }
        }
      }

      int result = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
  vector<vector<int>> grid(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s;
  cout << s.maxDistance(grid) << endl;

  return 0;
}