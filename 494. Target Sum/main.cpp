#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();

    vector<int> dp(40002);
    dp[20001] = 1;

    for (int i = 0; i < n; i++) {
      vector<int> cur(40002);
      for (int j = 1000; j < 39002; j++) {
        int a = j + nums[i];
        int b = j - nums[i];

        cur[j] += dp[a];
        cur[j] += dp[b];
      }

      dp = cur;
    }

    return dp[target + 20001];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, T;
  cin >> N >> T;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.findTargetSumWays(arr, T) << endl;

  return 0;
}