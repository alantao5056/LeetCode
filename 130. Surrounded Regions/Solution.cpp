#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, M;

class Solution {
  private:
  int i_[4] = {0, 1, 0, -1};
  int j_[4] = {1, 0, -1, 0};
  int m, n;

  public:
    void solve(vector<vector<char>>& board) {
      m = board.size();
      n = board[0].size();
      for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') {
          bfs(i, 0, board);
        }
        if (board[i][n-1] == 'O') {
          bfs(i, n-1, board);
        }
      }

      for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') {
          bfs(0, j, board);
        }
        if (board[m-1][j] == 'O') {
          bfs(m-1, j, board);
        }
      }

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] == 'O') board[i][j] = 'X';
          else if (board[i][j] == '#') board[i][j] = 'O';
        }
      }
    }

    void bfs(int i, int j, vector<vector<char>>& board) {
      queue<int> q;

      q.push(i);
      q.push(j);
      board[i][j] = '#';
      while (!q.empty()) {
        int curI = q.front(); q.pop();
        int curJ = q.front(); q.pop();
        
        // up down left right
        for (int k = 0; k < 4; k++) {
          int nextI = curI + i_[k];
          int nextJ = curJ + j_[k];
          if (nextI >= m || nextI < 0 || nextJ >= n || nextJ < 0 || board[nextI][nextJ] != 'O') continue;

          q.push(nextI);
          q.push(nextJ);
          board[nextI][nextJ] = '#';
        }
      }
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> M >> N;
  vector<vector<char>> board(M, vector<char>(N, 0));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  Solution s;
  s.solve(board);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}