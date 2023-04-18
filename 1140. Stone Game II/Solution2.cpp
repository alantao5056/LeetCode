#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  private:
    int dp[101][101];
    int suf[101];
    int n;
  public:
    int stoneGameII(vector<int>& piles) {
      n = piles.size();
      suf[n] = 0;
      for (int i = n-1; i >= 0; i--) {
        suf[i] = suf[i+1] + piles[i];
      }
      return recursive(0, 1, piles);
    }

    int recursive(int idx, int m, vector<int>& piles) {
      if (idx == n) return 0;
      if (dp[idx][m] != 0) {
        return dp[idx][m];
      }

      int sum = 0;
      for (int x = 1; x <= 2*m; x++) {
        if (idx+x-1 == n) break;
        sum += piles[idx+x-1];
        dp[idx][m] = max(dp[idx][m], sum + suf[idx+x] - recursive(idx+x, max(x, m), piles));
      }
      return dp[idx][m];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> piles(N);
  for (int i = 0; i < N; i++) {
    cin >> piles[i];
  }

  Solution s;
  cout << s.stoneGameII(piles) << endl;

  return 0;
}