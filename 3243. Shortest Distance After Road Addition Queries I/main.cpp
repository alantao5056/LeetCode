#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> dist(n);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
      dist[i] = i;
      adj[i].push_back(i+1);
    }

    dist[n-1] = n-1;

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      int start = queries[i][0]; int end = queries[i][1];
      adj[start].push_back(end);

      priority_queue<pii> q;
      q.push({dist[start]+1, end});
      dist[end] = min(dist[end], dist[start]+1);

      while (!q.empty()) {
        pii cur = q.top(); q.pop();

        for (int nb : adj[cur.second]) {
          int newD = dist[cur.second]+1;
          if (dist[nb] > newD) {
            dist[nb] = newD;
            q.push({newD, nb});
          }
        }
      }

      ans[i] = dist[n-1];
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, Q; cin >> N >> Q;

  vector<vector<int>> queries(Q, vector<int>(2));
  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  Solution s;
  vector<int> ans = s.shortestDistanceAfterQueries(N, queries);
  for (int a : ans) {
    cout << a << endl;
  }

  return 0;
}