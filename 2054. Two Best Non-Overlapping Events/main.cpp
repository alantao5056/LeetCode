#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

struct Comp {
  inline bool operator() (const vector<int>& struct1, const vector<int>& struct2) {
    return (struct1[1] < struct2[1]);
  }
  bool operator() (const vector<int> & left, float right)
  {
    return left[1] < right;
  }
  bool operator() (float left, const vector<int> & right)
  {
    return left < right[1];
  }
};

class Solution {
public:
  int maxTwoEvents(vector<vector<int>>& events) {
    int n = events.size();

    events.push_back(vector<int>{0, -100, 0});
    sort(events.begin(), events.end(), Comp());

    vector<int> dp(n+1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int idx = lower_bound(events.begin(), events.end(), events[i][0], Comp()) - events.begin() - 1;

      dp[i] = max(dp[i-1], events[i][2]);
      ans = max(ans, dp[idx] + events[i][2]);
    }

    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;

  vector<vector<int>> events(N, vector<int>(3));
  for (int i = 0; i < N; i++) {
    cin >> events[i][0] >> events[i][1] >> events[i][2];
  }

  Solution s;
  cout << s.maxTwoEvents(events) << endl;

  return 0;
}