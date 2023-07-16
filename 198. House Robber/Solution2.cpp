#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n == 1) {
        return nums[0];
      }
      vector<int> dp(n);
      dp[0] = nums[0];
      dp[1] = max(dp[0], nums[1]);
      for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
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