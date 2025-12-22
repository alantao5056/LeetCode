#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int N = prices.size();   
    
    ll init = 0;
    ll cur = 0;
    for (int j = 0; j < N; j++) {
      init += prices[j] * strategy[j];
      if (j < k/2) {
        continue;
      } else if (j < k) {
        cur += prices[j];
      } else {
        cur += prices[j]*strategy[j];
      }
    }

    int i = k;
    ll ans = max(cur, init);
    while (i < N) {
      cur += (1-strategy[i]) * prices[i];

      cur -= prices[i-k/2];

      cur += prices[i-k] * strategy[i-k];
      ans = max(ans, cur);
      i++;
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, K; cin >> N >> K;

  vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    cin >> prices[i];
  }

  vector<int> strategy(N);
  for (int i = 0; i < N; i++) {
    cin >> strategy[i];
  }
  
  Solution s;
  cout << s.maxProfit(prices, strategy, K) << endl;

  return 0;
}


