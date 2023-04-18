#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string colors;

class Solution {
  public:
    int minCost(string colors, vector<int>& neededTime) {
      int n = colors.size();
      int result = 0;
      int curMax = 0;
      char prev = ' ';
      for (int i = 0; i < n; i++) {
        if (colors[i] != prev) {
          curMax = neededTime[i];
        } else if (neededTime[i] > curMax) {
          result += curMax;
          curMax = neededTime[i];
        } else {
          result += neededTime[i];
        }
        prev = colors[i];
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> colors;
  int N = colors.size();
  vector<int> neededTime(N);
  for (int i = 0; i < N; i++) {
    cin >> neededTime[i];
  }

  Solution s;
  cout << s.minCost(colors, neededTime) << endl;

  return 0;
}