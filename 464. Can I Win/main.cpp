#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  map<pair<int, int>, bool> dp;
  bool recursive(int rem, int bm, int mci) {
    if (rem <= 0) return false;
    if (dp.find({rem, bm}) != dp.end()) return dp[{rem, bm}];
    for (int i = 0; i < mci; i++) {
      if (!((1 << i) & bm)) {
        if (!recursive(rem-(i+1), bm | (1 << i), mci)) {
          dp[{rem, bm}] = true;
          return true;
        }
      }
    }

    dp[{rem, bm}] = false;

    return false;
  }
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal == 0) return true;
    if ((maxChoosableInteger * (maxChoosableInteger+1)) / 2  < desiredTotal) return false;
    return recursive(desiredTotal, 0, maxChoosableInteger);
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int mc, dt;
  cin >> mc >> dt;

  Solution s;
  cout << s.canIWin(mc, dt) << endl;

  return 0;
}