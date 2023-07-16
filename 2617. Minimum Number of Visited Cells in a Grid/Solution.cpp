#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int M, N;

class Solution {
  public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
      int M = grid.size();
      int N = grid[0].size();
      vector<vector<vector<int>>> right(M, vector<vector<int>>(N));
      vector<vector<vector<int>>> down(M, vector<vector<int>>(N));

      vector<vector<int>> result(M, vector<int>(N, 1000000000));
      map<int, int> cur;
      cur[1000000000] = 1;
      map<int, int> cur2;
      cur2[1000000000] = 1;
      result[0][0] = 1;

      int i2 = 0;
      int j2 = 0;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (i != 0 || j != 0) {
            result[i][j] = min(result[i][j], cur.begin()->first);
          }
          if (grid[i][j] != 0) {
            right[i][j].pb(result[i][j]+1);
            right[i][min(N-1, j+grid[i][j])].pb(-result[i][j]-1);
          }
          for (int r : right[i][j]) {
            if (r > 0) {
              if (cur.find(r) == cur.end()) {
                cur[r] = 1;
              } else {
                cur[r]++;
              }
            } else {
              if (cur[r*-1] > 1) {
                cur[r*-1]--;
              } else {
                cur.erase(r*-1);
              }
            }
          }

          if (i2 != 0 || j2 != 0) {
            result[i2][j2] = min(result[i2][j2], cur2.begin()->first);
          }

          if (grid[i2][j2] != 0) {
            down[i2][j2].pb(result[i2][j2]+1);
            down[min(M-1, i2 + grid[i2][j2])][j2].pb(-result[i2][j2]-1);
          }
          for (int d : down[i2][j2]) {
            if (d > 0) {
              if (cur2.find(d) == cur2.end()) {
                cur2[d] = 1;
              } else {
                cur2[d]++;
              }
            } else {
              if (cur2[d*-1] > 1) {
                cur2[d*-1]--;
              } else {
                cur2.erase(d*-1);
              }
            }
          }

          i2++;
          if (i2 == M) {
            i2 = 0;
            j2++;
          }
        }
      }
      return result[M-1][N-1] == 1000000000 ? -1 : result[M-1][N-1];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> M >> N;

  vector<vector<int>> grid(M, vector<int>(N));

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s = Solution();

  cout << s.minimumVisitedCells(grid) << endl;

  return 0;
}