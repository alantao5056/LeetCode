#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int q = queries.size();

    int start = 0;
    bool next = !(nums[0]%2);
    vector<pii> ps;
    for (int i = 1; i < n; i++) {
      bool p = nums[i]%2;
      if (p == next) {
        next = !next;
      } else {
        ps.push_back({start, i-1});
        start = i;
      }
    }

    ps.push_back({start, n-1});

    vector<bool> ans;
    for (vector<int> qq : queries) {
      int idx = upper_bound(ps.begin(), ps.end(), make_pair(qq[0], 1e9)) - ps.begin() - 1;
      if (idx >= 0 && qq[1] <= ps[idx].second) {
        ans.push_back(true);
      } else {
        ans.push_back(false);
      }
    }
    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, Q;
  cin >> N >> Q;

  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  vector<vector<int>> queries(Q, vector<int>(2));
  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  Solution s;
  vector<bool> ans = s.isArraySpecial(nums, queries);
  for (bool a : ans) {
    cout << a << endl;
  }

  return 0;
}