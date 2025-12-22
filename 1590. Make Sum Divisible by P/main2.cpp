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
    vector<int> pref(N+1);
    for (int i = 0; i < N; i++) {
      nums[i] %= p;
      s += nums[i]; s %= p;
      pref[i+1] = pref[i] + nums[i]; pref[i+1] %= p;
    }

    if (s == 0) return 0;

    map<int, int> prev;
    int res = INT_MAX;

    for (int i = 0; i <= N; i++) {
      int target;
      if (pref[i] >= s) {
        target = pref[i] - s;
      } else {
        target = pref[i] + p-s;
      }

      if (prev.find(target) != prev.end()) {
        res = min(res, i-prev[target]);
      }

      prev[pref[i]] = max(prev[pref[i]], i);
    }

    if (res == INT_MAX || res == N) {
      return -1;
    }
    return res;
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