#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, K;

class Solution {
  public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> dp(n);
      multiset<int> s;

      for (int i = 0; i < n; i++) {
        if (!s.empty()) {
          if (i > k) {
            s.erase(s.lower_bound(dp[i-k-1]));
          }
          dp[i] = max(nums[i], nums[i] + *s.rbegin());
        } else {
          dp[i] = nums[i];
        }
        s.insert(dp[i]);        
      }
      
      int result = -1000000000;
      for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> K;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.constrainedSubsetSum(nums, K) << endl;

  return 0;
}