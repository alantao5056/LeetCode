#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int minSideJumps(vector<int>& obstacles) {
      int MAX = 1000000000;
      int n = obstacles.size();
      vector<vector<int>> dp(n, vector<int>(3, MAX));

      dp[0][0] = 1;
      dp[0][1] = 0;
      dp[0][2] = 1;

      for (int i = 1; i < n; i++) {
        if (obstacles[i] != 1) { // top track
          dp[i][0] = min(dp[i-1][0], min(obstacles[i] == 2 ? MAX : dp[i-1][1]+1, obstacles[i] == 3 ? MAX : dp[i-1][2]+1));
        }
        if (obstacles[i] != 2) { // middle track
          dp[i][1] = min(dp[i-1][1], min(obstacles[i] == 1 ? MAX : dp[i-1][0]+1, obstacles[i] == 3 ? MAX : dp[i-1][2]+1));
        }
        if (obstacles[i] != 3) {
          dp[i][2] = min(dp[i-1][2], min(obstacles[i] == 2 ? MAX : dp[i-1][1]+1, obstacles[i] == 1 ? MAX : dp[i-1][0]+1));
        }
      }

      return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> obstacles(N);
  for (int i = 0; i < N; i++) {
    cin >> obstacles[i];
  }

  Solution s;
  cout << s.minSideJumps(obstacles) << endl;

  return 0;
}