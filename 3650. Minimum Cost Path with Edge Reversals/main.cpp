#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int minCost(int n, vector<vector<int>>& edges) {
    int m = edges.size();

    vector<vector<pii>> nxt(n, vector<pii>());
    for (int i = 0; i < m; i++) {
      nxt[edges[i][0]].push_back({edges[i][1], edges[i][2]});
      nxt[edges[i][1]].push_back({edges[i][0], 2*edges[i][2]});
    }

    vector<ll> minD(n, 10000000000LL);
    minD[0] = 0;

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      int cur = pq.top().second;
      ll d = pq.top().first;
      pq.pop();

      if (d > minD[cur]) continue;

      for (pii nb : nxt[cur]) {
        ll newd = d + nb.second;
        if (newd < minD[nb.first]) {
          minD[nb.first] = newd;
          pq.push({newd, nb.first});
        }
      }
    }
    
    return minD[n-1] == 10000000000LL ? -1 : minD[n-1];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, M; cin >> N >> M;

  vector<vector<int>> edges(M, vector<int>(3));
  for (int i = 0; i < M; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }

  Solution s;
  cout << s.minCost(N, edges) << endl;

  return 0;
}