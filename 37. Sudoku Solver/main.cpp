#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
  vector<vector<vector<int>>> notp;
  vector<vector<int>> square;
  queue<vector<int>> q;

  void initSquare() {
    int cnt = 0;
    for (int is = 0; is < 9; is += 3) {
      for (int js = 0; js < 9; js += 3) {
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            square[is+i][js+j] = cnt;
          }
        }

        cnt++;
      }
    }
  }

  void fill(vector<vector<char>>& board, int i, int j, int x) {
    for (int ii = 0; ii < 9; ii++) {
      for (int jj = 0; jj < 9; jj++) {
        if (i == ii || j == jj || square[i][j] == square[ii][jj]) {
          if (board[ii][jj] != '.') continue;
          if (notp[ii][jj][x] == false) {
            notp[ii][jj][x] = 1;
            notp[ii][jj][9]++;
            if (notp[ii][jj][9] == 8) {
              for (int k = 0; k < 9; k++) {
                if (notp[ii][jj][k] == 0) {
                  board[ii][jj] = '0'+k;
                  q.push({ii, jj, k});
                }
              }
            }
          }
        }
      }
    }
  }

public:
  void solveSudoku(vector<vector<char>>& board) {
    notp.resize(9, vector<vector<int>>(9, vector<int>(10)));
    square.resize(9, vector<int>(9));
    initSquare();

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          fill(board, i, j, board[i][j]-'0');
        }
      }
    }

    while (!q.empty()) {
      vector<int> cur = q.front(); q.pop();

      fill(board, cur[0], cur[1], cur[2]);
    }
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  vector<vector<char>> board(9, vector<char>(9));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
    }
  }

  Solution s;
  s.solveSudoku(board);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}