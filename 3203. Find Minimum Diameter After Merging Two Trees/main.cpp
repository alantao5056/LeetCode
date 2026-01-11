#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, M;

class Solution {
  pii dfs(vector<vector<int>>& adj, int cur, int par, int depth) {
    pii ans = {cur, depth};
    for (int nb : adj[cur]) {
      if (nb == par) continue;

      pii result = dfs(adj, nb, cur, depth+1);
      if (result.second > ans.second) {
        ans = result;
      }
    }

    return ans;
  }

public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size();
    int m = edges2.size();

    vector<vector<int>> adj1(n+1);
    for (int i = 0; i < n; i++) {
      adj1[edges1[i][0]].push_back(edges1[i][1]);
      adj1[edges1[i][1]].push_back(edges1[i][0]);
    }

    pii d1 = dfs(adj1, 0, -1, 0);
    pii d2 = dfs(adj1, d1.first, -1, 0);

    vector<vector<int>> adj2(m+1);
    for (int i = 0; i < m; i++) {
      adj2[edges2[i][0]].push_back(edges2[i][1]);
      adj2[edges2[i][1]].push_back(edges2[i][0]);
    }

    pii dd1 = dfs(adj2, 0, -1, 0);
    pii dd2 = dfs(adj2, dd1.first, -1, 0);

    return max(max(d2.second, dd2.second), ((d2.second+1) / 2) + ((dd2.second+1) / 2) + 1);
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> M;
  vector<vector<int>> edges1(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> edges1[i][0] >> edges1[i][1];
  }

  
  vector<vector<int>> edges2(M, vector<int>(2));
  for (int i = 0; i < M; i++) {
    cin >> edges2[i][0] >> edges2[i][1];
  }

  Solution s;
  cout << s.minimumDiameterAfterMerge(edges1, edges2) << endl;

  return 0;
}