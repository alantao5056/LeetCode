#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    int N = n;
    int M = meetings.size();

    set<pii> s;
    for (int i = 0; i < N; i++) {
      s.insert({0, i});
    }

    vector<int> used(N);

    for (int i = 0; i < M; i++) {
      pii cur = *s.begin();

      used[cur.second]++;
      if (cur.first <= meetings[i][0]) {
        // gap
        s.erase(s.begin());
        s.insert({meetings[i][1], cur.second});
      } else {
        s.erase(s.begin());
        s.insert({cur.first + meetings[i][1] - meetings[i][0], cur.second});
      }
    }

    int curMax = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (used[i] > curMax) {
        curMax = used[i];
        ans = i;
      }
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> meetings(M, vector<int>(2));
  for (int i = 0; i < M; i++) {
    cin >> meetings[i][0] >> meetings[i][1];
  }

  Solution s;

  cout << s.mostBooked(N, meetings) << endl;
  
  return 0;
}
