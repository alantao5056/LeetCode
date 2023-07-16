#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

class Solution {
  public:
    int n;
    int side;
    bool makesquare(vector<int>& matchsticks) {
      n = matchsticks.size();

      int total = 0;
      for (int i = 0; i < n; i++) {
        total += matchsticks[i];
      }

      side = total/4;
      if (total % 4 != 0) {
        return false;
      }

      return canMakeSqare(matchsticks, 0, 0, 0, 0, 0);
    }

    bool canMakeSqare(vector<int>& matchsticks, int curIdx, int s1, int s2, int s3, int s4) {
      if (s1 > side || s2 > side || s3 > side || s4 > side) {
        return false;
      }

      if (curIdx == n) {
        if (s1 == side && s2 == side && s3 == side && s4 == side) {
          return true;
        }
        return false;
      }

      bool r1 = canMakeSqare(matchsticks, curIdx + 1, s1 + matchsticks[curIdx], s2, s3, s4);
      if (r1) {
        return true;
      }
      bool r2 = canMakeSqare(matchsticks, curIdx + 1, s1, s2 + matchsticks[curIdx], s3, s4);
      if (r2) {
        return true;
      }
      bool r3 = canMakeSqare(matchsticks, curIdx + 1, s1, s2, s3 + matchsticks[curIdx], s4);
      if (r3) {
        return true;
      }
      bool r4 = canMakeSqare(matchsticks, curIdx + 1, s1, s2, s3, s4 + matchsticks[curIdx]);
      if (r4) {
        return true;
      }
      return false;
    }
};

int N;

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> matchsticks(N);
  for (int i = 0; i < N; i++) {
    cin >> matchsticks[i];
  }

  Solution s;
  cout << ((s.makesquare(matchsticks) == 0) ? "false" : "true") << endl;

  return 0;
}