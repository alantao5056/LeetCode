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
      int maxDays = days[n-1];
      vector<int> dp(maxDays+1);
      vector<bool> days2(maxDays+1);
      for (int i = 0; i < n; i++) {
        days2[days[i]] = true;
      }
      for (int i = 1; i <= maxDays; i++) {
        if (days2[i]) {
          dp[i] = min(dp[i-1] + costs[0], min(dp[max(i-7, 0)] + costs[1], dp[max(i-30, 0)] + costs[2]));
        } else {
          dp[i] = dp[i-1];
        }
      }

      return dp[maxDays];
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