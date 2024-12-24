#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int ans = 0;
  ll recursive(vector<vector<int>>& adj, vector<int>& values, int k, int cur, int par) {
    ll ret = 0;
    for (int nb : adj[cur]) {
      if (nb == par) continue;
      ret += recursive(adj, values, k, nb, cur);
    }

    ret += values[cur];

    if (ret % k == 0) ans++;
    return ret;
  }

  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }

    recursive(adj, values, k, 0, -1);

    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, K;
  cin >> N >> K;

  vector<vector<int>> edges(N, vector<int>(2));
  for (int i = 0; i < N-1; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  vector<int> values(N);
  for (int i = 0; i < N; i++) {
    cin >> values[i];
  }

  Solution s;
  cout << s.maxKDivisibleComponents(N, edges, values, K) << endl;

  return 0;
}