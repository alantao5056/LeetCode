#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

class Solution {
public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<set<int>> dp(n);

    if (stones[1] != 1) return false;

    dp[1].insert(1);
    for (int i = 2; i < n; i++) {
      for (int j = i-1; j >= 1; j--) {
        int dist = stones[i] - stones[j];
        if (dp[j].find(dist) != dp[j].end() ||
            dp[j].find(dist+1) != dp[j].end() || 
            dp[j].find(dist-1) != dp[j].end()) {
          dp[i].insert(dist);
        }
      }
    }

    return dp[n-1].size();
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.canCross(arr) << endl;

  return 0;
}