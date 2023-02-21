#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int N;

class Solution {
  public:
    int numSquares(int n) {
      vector<int> dp(n+1, INT_MAX);

      dp[0]=0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
          dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
      }

      return dp[n];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;

  Solution s;
  cout << s.numSquares(N) << endl;

  return 0;
}