#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int dist(int a, int b, int r) {
    return min(abs(a-b), r-abs(a-b));
  }

  int findRotateSteps(string ring, string key) {
    int r = ring.size();
    int k = key.size();

    vector<vector<int>> dp(k, vector<int>(r, 1e9));
    for (int i = 0; i < r; i++) {
      if (ring[i] == key[0]) {
        dp[0][i] = dist(0, i, r);
      }
    }

    for (int i = 1; i < k; i++) {
      for (int j = 0; j < r; j++) {
        if (key[i] != ring[j]) continue;

        for (int l = 0; l < r; l++) {
          if (key[i-1] != ring[l]) continue;
          dp[i][j] = min(dp[i][j], dp[i-1][l] + dist(j, l, r));
        }
      }
    }

    int ans = 1e9;
    for (int i = 0; i < r; i++) {
      ans = min(ans, dp[k-1][i]);
    }

    return ans + k;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string ring, key;
  cin >> ring >> key;

  Solution s;
  cout << s.findRotateSteps(ring, key) << endl;

  return 0;
}