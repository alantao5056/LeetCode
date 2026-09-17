#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
  // left, up, right, down
  vector<vector<bool>> s = {
    {0, 0, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 0, 1},
    {0, 0, 1, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 0}
  };

  vector<int> i_ = {0, -1, 0, 1};
  vector<int> j_ = {-1, 0, 1, 0};

  int N, M;
  vector<vector<int>> g;
  vector<vector<bool>> v;


public:
  int ti(int i, int d) {
    return i+i_[d];
  }
  int tj(int j, int d) {
    return j+j_[d];
  }
  int inv(int d) {
    return (d+2)%4;
  }

  bool path(int i, int j, int d) {
    if (s[g[i][j]][d] == 0) return false;
    if (s[g[ti(i, d)][tj(j, d)]][inv(d)] == 0) return false;
    return true;
  }

  bool hasValidPath(vector<vector<int>>& grid) {
    N = grid.size(); M = grid[0].size();
    if (N == 1 && M == 1) return true;
    g.resize(N+2, vector<int>(M+2));
    v.resize(N+2, vector<bool>(M+2));
    for (int i = 1; i <= N; i++) {
      v[i][0] = v[i][M+1] = 0;
      for (int j = 1; j <= M; j++) {
        v[N+1][j] = v[0][j] = 0;
        g[i][j] = grid[i-1][j-1];
      }
    }

    bool ans = false;
    v[1][1] = true;
    for (int x = 0; x < 4; x++) {
      if (s[g[1][1]][x] == 0) continue;
      if (!path(1, 1, x)) continue;
      int i = ti(1, x);
      int j = tj(1, x);
      if (v[i][j]) continue;
      v[i][j] = true;
      
      while (i != N || j != M) {
        bool works = false;
        for (int d = 0; d < 4; d++) {
          int ni = ti(i, d);
          int nj = tj(j, d);
          if (!path(i, j, d) || v[ni][nj]) continue;
          v[ni][nj] = true;
          works = true;
          i = ni;
          j = nj;
          break;
        }
        if (!works) break;
      }

      if (i == N && j == M) {
        ans = true;
        break;
      }
    }

    return ans;
  }
};

int main() {
  // freopen("0.in", "r", stdin);
  // freopen("0.out", "w", stdout);

  int N, M; cin >> N >> M;

  vector<vector<int>> grid(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s;
  cout << s.hasValidPath(grid) << endl;
}
