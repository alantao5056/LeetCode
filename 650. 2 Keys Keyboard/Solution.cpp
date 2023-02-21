#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int N;

class Solution {
  public:
    int minSteps(int n) {
      vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX/2));
      // i is number of current copied
      // j is number of cur existing
      dp[0][1] = 0;

      for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
          dp[i][j] = dp[i][j-i] + 1;
          if (i == j) {
            int min_ = INT_MAX/2;
            for (int k = 0; k < i; k++) {
              min_ = min(dp[k][j], min_);
            }
            dp[i][j] = min(dp[i][j], min_+1);
          }
        }
      }

      int min_ = INT_MAX/2;
      for (int k = 0; k <= n; k++) {
        min_ = min(dp[k][n], min_);
      }

      return min_;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  Solution s;
  cout << s.minSteps(N) << endl;

  return 0;
}