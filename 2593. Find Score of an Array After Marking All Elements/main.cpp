#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  long long findScore(vector<int>& nums) {
    int n = nums.size();
    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
      se.insert({nums[i], i});
    }

    long long score = 0;
    while (se.size() > 0) {
      pair<int, int> m = *se.begin();
      se.erase(m);
      score += m.first;
      int next = m.second+1;
      int prev = m.second-1;
      if (next < n && se.find({nums[next], next}) != se.end()) {
        se.erase({nums[next], next});
      }
      if (prev >= 0 && se.find({nums[prev], prev}) != se.end()) {
        se.erase({nums[prev], prev});
      }
    }

    return score;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.findScore(nums) << endl;

  return 0;
}