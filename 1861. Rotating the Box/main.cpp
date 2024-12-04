#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, M;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      int n = box.size();
      int m = box[0].size();
      vector<vector<char>> result(m, vector<char>(n, '.'));
      for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
          if (box[i][j] == '#') {
            cur++;
          } else if (box[i][j] == '*') {
            result[j][n-i-1] = '*';

            for (int k = 1; k <= cur; k++) {
              result[j-k][n-i-1] = '#';
            }
            cur = 0;
          }
        }
        for (int k = 1; k <= cur; k++) {
          result[m-k][n-i-1] = '#';
        }
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> M;
  vector<vector<char>> box(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < M; j++) {
      box[i][j] = s[j];
    }
  }

  Solution s;
  vector<vector<char>> ans = s.rotateTheBox(box);

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << ans[i][j] << ' ';
    }

    cout << endl;
  }

  return 0;
}