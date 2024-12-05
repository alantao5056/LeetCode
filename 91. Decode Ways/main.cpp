#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    s = ' ' + s;

    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i] != '0') {
        dp[i] += dp[i-1];
      }
      
      int p = s[i-1] - '0';
      int c = s[i] - '0';

      if (i == 1) continue;
      if (p == 1) {
        dp[i] += dp[i-2];
      } else if (p == 2 && c <= 6) {
        dp[i] += dp[i-2];
      }
    }

    return dp[n];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s;
  cin >> s;
  
  Solution so;
  cout << so.numDecodings(s) << endl;

  return 0;
}