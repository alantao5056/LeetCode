#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
  public:
    bool hasValidPath(vector<vector<int>>& grid) {
      int N = grid.size();
      int M = grid[0].size();

      vector<vector<bool>> visited(N+2, vector<bool>(M+2));
      vector<vector<pair<pii, pii>>> s(N+2, vector<pair<pii, pii>>(M+2, make_pair(make_pair(0, 0), make_pair(0, 0))));
      for (int i = 1; i <= N; i++) {
        visited[i][0] = true;
        visited[i][M+1] = true;
        for (int j = 1; j <= M; j++) {
          visited[0][j] = true;
          visited[N+1][j] = true;
          switch (grid[i-1][j-1]) {
            case 1:
              s[i][j].first = {0, -1};
              s[i][j].second = {0, 1};
              break;
            case 2:
              s[i][j].first = {-1, 0};
              s[i][j].second = {1, 0};
              break;
            case 3:
              s[i][j].first = {0, -1};
              s[i][j].second = {1, 0};
              break;
            case 4:
              s[i][j].first = {0, 1};
              s[i][j].second = {1, 0};
              break;
            case 5:
              s[i][j].first = {0, -1};
              s[i][j].second = {-1, 0};
              break;
            case 6:
              s[i][j].first = {0, 1};
              s[i][j].second = {-1, 0};
              break;
          }
        }
      }

      queue<pii> q;
      q.push({1, 1});
      visited[1][1] = true;
      bool ans = false;
      while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i == N && j == M) {
          ans = true;
          break;
        }

        int i1 = i+s[i][j].first.first;
        int j1 = j+s[i][j].first.second;

        if (!visited[i1][j1] && ((i1+s[i1][j1].first.first == i && j1 + s[i1][j1].first.second == j) || (i1+s[i1][j1].second.first == i && j1 + s[i1][j1].second.second == j))) {
          visited[i1][j1] = true;
          q.push({i1, j1});
        }

        int i2 = i+s[i][j].second.first;
        int j2 = j+s[i][j].second.second;

        if (!visited[i2][j2] && ((i2+s[i2][j2].first.first == i && j2 + s[i2][j2].first.second == j) || (i2+s[i2][j2].second.first == i && j2 + s[i2][j2].second.second == j))) {
          visited[i2][j2] = true;
          q.push({i2, j2});
        }
      }

      return ans;
    }
};

int main() {
  freopen("0.in", "r", stdin);
  freopen("0.out", "w", stdout);
  cout << ans << endl;

  return 0;
}
