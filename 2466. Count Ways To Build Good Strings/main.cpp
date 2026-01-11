#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high+1);

    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
      if (i-zero >= 0) {
        dp[i] += dp[i-zero];
        dp[i] %= MOD;
      }
      if (i -one >= 0) {
        dp[i] += dp[i-one];
        dp[i] %= MOD;
      }
    }

    int ans = 0;
    for (int i = low; i <= high; i++) {
      ans += dp[i];
      ans %= MOD;
    }

    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int low, high, zero, one;
  cin >> low >> high >> zero >> one;

  Solution s;
  cout << s.countGoodStrings(low, high, zero, one) << endl;

  return 0;
}