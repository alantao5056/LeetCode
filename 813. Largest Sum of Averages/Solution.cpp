#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, k;

class Solution {
  public:
    double largestSumOfAverages(vector<int>& nums, int k) {
      int n = nums.size();
      nums.insert(nums.begin(), 0);

      vector<vector<double>> dp(k+1, vector<double>(n+1));

      for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
          double cur = nums[j];
          for (int k = j-1; k >= 0; k--) {
            dp[i][j] = max(dp[i][j], cur / ((double)(j-k)) + dp[i-1][k]);
            cur += nums[k];
          }
        }
      }
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> k;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.largestSumOfAverages(nums, k) << endl;

  return 0;
}