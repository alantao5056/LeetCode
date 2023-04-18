#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int target) {
      return recursive(nums, target, 0, 0);
    }

    int recursive(vector<int>& nums, int target, int cur, int i) {
      if (i == nums.size()) {
        return cur == target;
      }

      return recursive(nums, target, cur + nums[i], i+1) + recursive(nums, target, cur - nums[i], i+1);
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int target;
  cin >> N >> target;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.findTargetSumWays(nums, target) << endl;

  return 0;
}