#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int numTeams(vector<int>& rating) {
      int n = rating.size();
      int result = 0;
      vector<vector<int>> lessThan(n, vector<int>());
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (rating[j] < rating[i]) {
            lessThan[i].pb(j);
            result += lessThan[j].size();
          }
        }
      }

      vector<vector<int>> moreThan(n, vector<int>());
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (rating[j] > rating[i]) {
            moreThan[i].pb(j);
            result += moreThan[j].size();
          }
        }
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> rating(N);
  for (int i = 0; i < N; i++) {
    cin >> rating[i];
  }

  Solution s;
  cout << s.numTeams(rating) << endl;

  return 0;
}