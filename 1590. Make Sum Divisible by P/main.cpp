#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int N = nums.size();
    int s = 0;
    for (int i = 0; i < N; i++) {
      nums[i] %= p;
      s += nums[i]; s %= p;
    }

    if (s == 0) return 0;

    int l = 0;
    int r = 0;
    int cur = nums[0];
    int res = INT_MAX;

    while (l < N && r < N) {
      if (cur < s) {
        r++;
        if (r < N) {
          cur += nums[r];
        }
      } else if (cur > s) {
        if (l == r) {
          l++; r++;
          if (l < N) {
            cur = nums[l];
          }
        } else {
          cur -= nums[l];
          l++;
        }
      } else {
        res = min(res, r-l+1);
        cur -= nums[l];
        l++;
        if (cur == s) continue;
        r++;
        if (r < N) {
          cur += nums[r];
        }
      }
    }

    return (res == INT_MAX || res == N) ? -1 : res;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, P; cin >> N >> P;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.minSubarray(arr, P) << endl;

  return 0;
}