#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    int N = n;
    int M = meetings.size();

    vector<ll> ends(N);
    vector<int> used(N);

    for (int i = 0; i < M; i++) {
      bool assigned = false;
      ll minEnd = LLONG_MAX;
      int target = 0;
      for (int j = 0; j < N; j++) {
        if (ends[j] <= meetings[i][0]) {
          // can take
          assigned = true;
          ends[j] = meetings[i][1];
          used[j]++;
          break;
        }

        if (ends[j] < minEnd) {
          minEnd = ends[j];
          target = j;
        }
      }

      if (!assigned) {
        ends[target] += meetings[i][1] - meetings[i][0];
        used[target]++;
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

