#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

class Solution {
public:
  long long continuousSubarrays(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(3, 1)); // down, mid, up

    long long ans = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i-1])  {
        if (nums[i] - nums[i-1] == 2) {
          dp[i][0] += dp[i-1][2];
        }
        if (nums[i] - nums[i-1] == 1) {
          dp[i][1] += dp[i-1][2];
          dp[i][0] += dp[i-1][1];
        }
      } else if (nums[i] < nums[i-1]) {
        if (nums[i-1] - nums[i] == 2) {
          dp[i][2] += dp[i-1][0];
        }
        if (nums[i-1] - nums[i] == 1) {
          dp[i][1] += dp[i-1][0];
          dp[i][2] += dp[i-1][1];
        }
      } else { // equal
        dp[i][0] += dp[i-1][0];
        dp[i][1] += dp[i-1][1];
        dp[i][2] += dp[i-1][2];
      }

      ans += max(dp[i][0], max(dp[i][1], dp[i][2]));
    }

    return ans;
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
  cout << s.continuousSubarrays(arr) << endl;

  return 0;
}