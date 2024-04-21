#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;
    vector<vector<int>> next(n, vector<int>());

    for (int i = 0; i < edges.size(); i++) {
      next[edges[i][0]].push_back(edges[i][1]);
      next[edges[i][1]].push_back(edges[i][0]);
    }

    queue<int> q;
    vector<bool> visited(n);
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (int ne : next[cur]) {
        if (visited[ne]) continue;
        q.push(ne);
        visited[ne] = true;
        if (ne == destination) return true;
      }
    }

    return false;
  }
};

int N, source, destination;

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> source >> destination;
  vector<vector<int>> edges(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  Solution s;
  cout << s.validPath(N, edges, source, destination) << endl;

  return 0;
}