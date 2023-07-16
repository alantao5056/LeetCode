#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
      if (n < 3) {
        return 0;
      }
      vector<int> diff(n-1);
      for (int i = 0; i < n-1; i++) {
        diff[i] = nums[i+1] - nums[i];
      }

      int curDiff = diff[0];
      int streak = 1;
      int count = 0;
      for (int i = 1; i < n-1; i++) {
        if (diff[i] == curDiff) {
          streak++;
        } else {
          // process streak
          count += seq(streak-1);
          streak = 1;
          curDiff = diff[i];
        }
      }

      // process streak
      count += seq(streak-1);
      return count;
    }

    int seq(int n) {
      return (n*(n+1))/2;
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
  cout << s.numberOfArithmeticSlices(nums) << endl;

  return 0;
}