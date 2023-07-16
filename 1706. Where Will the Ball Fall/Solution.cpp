#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int M, N;

class Solution {
  public:
    vector<vector<bool>> grid2;
    int m, n;
    vector<int> findBall(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();

      for (int i = 0; i < m; i++) {
        vector<bool> v(n);
        grid2.pb(v);
        for (int j = 0; j < n; j++) {
          grid2[i][j] = grid[i][j] == 1;
        }
      }

      vector<int> result(n);
      for (int i = 0; i < n; i++) {
        result[i] = recursive(0, i);
      }
      return result;
    }

    int recursive(int i, int j) {
      if (i == m) {
        return j;
      }

      if (grid2[i][j]) {
        if (j == n-1) {
          return -1;
        }

        if (!grid2[i][j+1]) {
          return -1;
        }
        return recursive(i+1, j+1);
      } else {
        if (j == 0) {
          return -1;
        }

        if (grid2[i][j-1]) {
          return -1;
        }
        return recursive(i+1, j-1);
      }
      return 0;
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

  Solution s;
  vector<int> result = s.findBall(grid);
  for (int i = 0; i < N; i++) {
    cout << result[i] << endl;
  }

  return 0;
}