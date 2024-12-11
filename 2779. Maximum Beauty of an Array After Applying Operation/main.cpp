#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    priority_queue<int, vector<int>, greater<int>> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int start = nums[i] - k;
      int end = nums[i] + k;
      if (!s.empty() && s.top() < start) {
        s.pop();
      }

      s.push(end);
      ans = max(ans, (int)s.size());
    }

    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, K;
  cin >> N >> K;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.maximumBeauty(arr, K) << endl;

  return 0;
}