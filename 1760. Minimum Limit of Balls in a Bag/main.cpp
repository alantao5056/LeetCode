#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int n = nums.size();

    int low = 1;
    int high = 1000000001;
    
    while (low < high) { // notice we do not compare element at mid with our target
      int mid = low + (high - low) / 2;

      int ans = 0;
      for (int nu : nums) {
        if (nu % mid == 0) {
          ans += nu/mid - 1;
        } else {
          ans += nu / mid;
        }
      }

      if (ans <= maxOperations)
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, M;
  cin >> N >> M;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.minimumSize(nums, M) << endl;

  return 0;
}