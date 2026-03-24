#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<ll> dp(10001);

    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = 0; j+coins[i] <= amount; j++) {
        if (dp[j+coins[i]] < INT_MAX) {
          dp[j+coins[i]] += dp[j];
        }
      }
    }

    return dp[amount];
  }
};

int main() {
  int N, A; cin >> N >> A;
  vector<int> coins(N);
  for (int i = 0; i < N; i++) {
    cin >> coins[i];
  }

  Solution s; cout << s.change(A, coins) << endl;
  return 0;
}
