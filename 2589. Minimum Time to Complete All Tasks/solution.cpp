#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int findMinimumTime(vector<vector<int>>& tasks) {
      sort(tasks.begin(), tasks.end(), less_than_key());

      vector<bool> visit(2001, false);

      for (vector<int>& t : tasks) {
        int s = t[0];
        int e = t[1];
        int d = t[2];

        int cnt = 0;
        for (int i = s; i <= e; i++) {
          if (visit[i]) cnt++;
        }

        if (cnt >= d) {
          // already done
          continue;
        }

        int diff = d-cnt;
        while (diff > 0) {
          if (!visit[e]) {
            visit[e] = true;
            diff--;
          }
          e--;
        }
      }

      int cnt = 0;
      for (int i = 0; i <= 2000; i++) {
        if (visit[i]) cnt++;
      }

      return cnt;
    }

  private:
    struct less_than_key {
      inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
        return (v1[1] < v2[1]);
      }
    };
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;

  vector<vector<int>> tasks(N, vector<int>(3));

  for (int i = 0; i < N; i++) {
    cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
  }

  Solution s;

  cout << s.findMinimumTime(tasks) << endl;

  return 0;
}