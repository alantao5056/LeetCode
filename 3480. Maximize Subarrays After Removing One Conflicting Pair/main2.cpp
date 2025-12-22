#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    int m = conflictingPairs.size();
    vector<vector<pair<int, int>>> rmap(n+1);
    for (int i = 0; i < m; i++) {
      if (conflictingPairs[i][0] > conflictingPairs[i][1]) {
        swap(conflictingPairs[i][0], conflictingPairs[i][1]);
      }
    }

    sort(conflictingPairs.begin(), conflictingPairs.end(), [](const auto& a, const auto& b) {
      return a[1] < b[1];
    });

    for (int i = 0; i < m; i++) {
      rmap[conflictingPairs[i][1]].push_back({conflictingPairs[i][0], i});
    }

    vector<long long> bonus(m);
    vector<vector<int>> tops(n+1, vector<int>{0, 0, -1}); // first, second, first index
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      tops[i] = tops[i-1];
      for (auto r : rmap[i]) {
        if (r.first > tops[i][0]) {
          tops[i][1] = tops[i][0];
          tops[i][0] = r.first;
          tops[i][2] = r.second;
        } else if (r.first > tops[i][1]) {
          tops[i][1] = r.first;
        }
      }

      res += i - tops[i][0];

      if (tops[i][2] != -1) {
        bonus[tops[i][2]] += tops[i][0] - tops[i][1];
      }
    }

    return res + *max_element(bonus.begin(), bonus.end());
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n, m; cin >> n >> m;

  vector<vector<int>> cps(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> cps[i][0] >> cps[i][1];
  }

  Solution s;
  cout << s.maxSubarrays(n, cps) << endl; 

  return 0;
}