#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int N;

class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n);
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          dp[i] = nums[i];
        } else if (i == 1) {
          dp[i] = max(dp[i-1], nums[i]);
        } else {
          dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
      }

      return dp[n-1];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.rob(nums) << endl;

  return 0;
}