#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      int n = nums.size();
      if (n == 1) {
        return nums[0];
      }

      ll result = 0;

      int direction = 0; // 1 going up; 2 going down
      for (int i = 0; i < n-1; i++) {
        if (nums[i+1] == nums[i]) continue;
        if (nums[i+1] > nums[i]) {
          // lose nums[i]
          if (direction == 2) {
            result -= nums[i];
          }
          direction = 1;
        } else {
          // gain nums[i]
          if (direction == 1 || direction == 0) {
            result += nums[i];
          }
          direction = 2;
        }
      }

      if ((nums[n-1] > nums[n-2]) || (nums[n-1] == nums[n-2] && direction == 1)) {
        result += nums[n-1];
      }

      return result;
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
  cout << s.maxAlternatingSum(nums) << endl;

  return 0;
}