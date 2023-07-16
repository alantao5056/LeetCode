#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      int n = days.size();
      vector<vector<int>> dp(4, vector<int>(n+1, 1000000000));
      for (int i = 1; i <= n; i++) {
        dp[1][i] = costs[0]*i;
      }

      vector<int> lens = {1, 7, 30};

      dp[1][0] = 0;
      dp[2][0] = 0;
      dp[3][0] = 0;

      int newj = 0;
      for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
          newj = j;
          while (newj > 0 && days[newj-1] > days[j-1]-lens[i-1]) {
            newj--;
          }

          dp[i][j] = min(dp[i-1][j], dp[i][newj]+costs[i-1]);
        }
      }

      return dp[3][n];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> costs(3);
  cin >> costs[0] >> costs[1] >> costs[2];
  vector<int> days(N);
  for (int i = 0; i < N; i++) {
    cin >> days[i];
  }

  Solution s;
  cout << s.mincostTickets(days, costs) << endl;

  return 0;
}