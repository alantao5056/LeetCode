#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int N;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      prices.pb(INT_MIN);
      int n = prices.size();
      int bought = -1;
      int profit = 0;
      for (int i = 0; i < n-1; i++) {
        if (prices[i+1] < prices[i]) {
          // sell
          if (bought != -1) {
            profit += prices[i] - bought;
            bought = -1;
          }
        } else {
          // buy
          if (bought == -1) {
            bought = prices[i];
          }
        }
      }
      return profit;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    cin >> prices[i];
  }

  Solution s;
  cout << s.maxProfit(prices) << endl;

  return 0;
}