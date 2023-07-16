#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, fee;

class Solution {
  public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();

      vector<pii> dp(n);
      dp[0] = {-prices[0], 0};

      for (int i = 1; i < n; i++) {
        pii cur = {0, 0};

        cur.first = max(dp[i-1].first, dp[i-1].second - prices[i]);
        cur.second = max(dp[i-1].second, dp[i-1].first + prices[i] - fee);
        dp[i] = cur;
      }

      return dp[n-1].second;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> fee;
  vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    cin >> prices[i];
  }

  Solution s;

  cout << s.maxProfit(prices, fee) << endl;

  return 0;
}