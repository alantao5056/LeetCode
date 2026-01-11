#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  void parents(vector<int>& pars, vector<vector<int>>& nbs, int cur, int par) {
    for (int nb : nbs[cur]) {
      if (nb == par) continue;
      pars[nb] = cur;
      parents(pars, nbs, nb, cur);
    }
  }

  void xors(vector<int>& pars, vector<ll>& xorVals, vector<int>& nums, vector<vector<int>>& nbs, int cur) {
    xorVals[cur] = nums[cur];
    for (int nb : nbs[cur]) {
      if (nb != pars[cur]) {
        xors(pars, xorVals, nums, nbs, nb);
        xorVals[cur] ^= xorVals[nb];
      }
    }
  }

  ll calc(ll a, ll b, ll c) {
    return max(a, max(b, c)) - min(a, min(b, c));
  }

  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>> nbs(n);
    for (auto e : edges) {
      nbs[e[0]].push_back(e[1]);
      nbs[e[1]].push_back(e[0]);
    }

    vector<int> pars(n, -1);
    parents(pars, nbs, 0, -1);

    vector<ll> xorVals(n);
    xors(pars, xorVals, nums, nbs, 0);

    deque<int> q;
    for (int nb : nbs[0]) {
      q.push_back(nb);
    }

    ll res = LLONG_MAX;

    while (!q.empty()) {
      int cur = q.front(); q.pop_front();

      for (int nb : nbs[cur]) {
        if (nb != pars[cur]) {
          q.push_back(nb);
        }
      }

      // outside
      deque<int> qq;
      for (int nb : nbs[0]) {
        qq.push_back(nb);
      }

      while (!qq.empty()) {
        int curr = qq.front(); qq.pop_front();
        if (curr == cur) continue;

        res = min(res, calc(xorVals[cur], xorVals[curr], xorVals[0] ^ xorVals[cur] ^ xorVals[curr]));

        for (int nb : nbs[curr]) {
          if (nb != pars[curr]) {
            qq.push_back(nb);
          }
        }
      }

      // inside
      for (int nb : nbs[cur]) {
        if (nb != pars[cur]) {
          qq.push_back(nb);
        }
      }

      while (!qq.empty()) {
        int curr = qq.front(); qq.pop_front();

        res = min(res, calc(xorVals[cur] ^ xorVals[curr], xorVals[curr], xorVals[0] ^ xorVals[cur]));

        for (int nb : nbs[curr]) {
          if (nb != pars[curr]) {
            qq.push_back(nb);
          }
        }
      } 
    }
    
    return res;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n; cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<vector<int>> edges(n-1, vector<int>(2));
  for (int i = 0; i < n-1; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  Solution s;

  cout << s.minimumScore(nums, edges) << endl;

  return 0;
}