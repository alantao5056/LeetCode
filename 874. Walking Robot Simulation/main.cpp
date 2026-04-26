#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      set<pair<int, int>> os;

      for (int i = 0; i < obstacles.size(); i++) {
        os.insert(make_pair(obstacles[i][0], obstacles[i][1]));
      }

      int ans = 0;
      int dir = 0;
      int x = 0;
      int y = 0;
      // 0 = north
      // 1 = east
      // 2 = south
      // 3 = west
      for (int i = 0; i < commands.size(); i++) {
        int c = commands[i];

        if (c == -1) {
          dir++;
          dir %= 4;
        } else if (c == -2) {
          dir--;
          dir = dir < 0 ? (dir + 4) : dir;
        } else {
          for (int j = 0; j < c; j++) {
            int nx = x; int ny = y;
            if (dir == 0) {
              ny++;
            } else if (dir == 1) {
              nx++;
            } else if (dir == 2) {
              ny--;
            } else {
              nx--;
            }

            if (os.find(make_pair(nx, ny)) != os.end()) {
              break;
            }

            x = nx;
            y = ny;
            ans = max(ans, x*x + y*y);
          }
        }
      }

      return ans;
    }
};

int main() {
  int C, O; cin >> C >> O;
  vector<int> commands(C);
  for (int i = 0; i < C; i++) {
    cin >> commands[i];
  }

  vector<vector<int>> obstacles(O, vector<int>(2));
  for (int i = 0; i < O; i++) {
    cin >> obstacles[i][0] >> obstacles[i][1];
  }

  Solution s;

  cout << s.robotSim(commands, obstacles) << endl;

  return 0;
}
