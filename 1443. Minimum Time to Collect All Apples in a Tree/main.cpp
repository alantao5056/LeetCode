#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> nbs;
  int recurse(int cur, int par, vector<bool>& hasApple) {
    int total = 0;
    for (int nb : nbs[cur]) {
      if (nb == par) continue;
      total += recurse(nb, cur, hasApple);
    }

    if (hasApple[cur] || total > 0) total += 2;
    return total;
  }
  
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    nbs.resize(n);
    for (int i = 0; i < n-1; i++) {
      nbs[edges[i][0]].push_back(edges[i][1]);
      nbs[edges[i][1]].push_back(edges[i][0]);
    }

    int total = 0;
    for (int nb : nbs[0]) {
      total += recurse(nb, 0, hasApple);
    }

    return total;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n; cin >> n;

  vector<vector<int>> edges(n-1, vector<int>(2));
  for (int i = 0; i < n-1; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  vector<bool> hasApple(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    hasApple[i] = x;
  }

  Solution s;
  cout << s.minTime(n, edges, hasApple) << endl;

  return 0;
}