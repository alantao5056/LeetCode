#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int N = nums.size();

    vector<vector<int>> dp(N, vector<int>(1001, 1)); // dp[idx][diff]

    vector<int> app(501, -1);
    int ans = 1;
    for (int i = 0; i < N; i++) {
      for (int j = -500; j < 501; j++) {
        int target = nums[i] - j;
        if (target >= 0 && target <= 500 && app[target] != -1) {
          dp[i][j+500] = dp[app[target]][j+500] + 1;
          ans = max(ans, dp[i][j+500]);
        }
      }
      app[nums[i]] = i;
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N;
  cin >> N;
  
  vector<int> nums(N);

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.longestArithSeqLength(nums) << endl;

  return 0;
}