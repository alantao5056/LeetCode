#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();

    int m = 0;
    int c = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        if ((1 << i) & mask) {
          cur |= nums[i];
        }
      }

      if (cur > m) {
        m = cur;
        c = 1;
      } else if (cur == m) {
        c++;
      }
    }

    return c;
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
  cout << s.countMaxOrSubsets(nums) << endl;

  return 0;
}