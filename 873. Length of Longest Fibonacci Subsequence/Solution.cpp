#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int lenLongestFibSubseq(vector<int>& arr) {
      int n = arr.size();
      vector<vector<int>> dp1(n); // prev index
      vector<int> dp2(n); // len

      int result = 0;
      for (int i = 0; i < n; i++) {
        set<int> s;
        for (int j = 0; j < i; j++) {
          if (dp1[j].size() == 0) { // not defined
            if (s.find(arr[i]-arr[j]) != s.end()) {
              // update
              if (dp2[i] < 3) {
                dp2[i] = 3;
                dp1[i].clear();
                dp1[i].pb(j);
              } else if (dp2[i] == 3) {
                dp1[i].pb(j);
              }
            }
          } else {
            for (int d : dp1[j]) {
              if (arr[d] == arr[i]-arr[j]) {
                // update
                if (dp2[i] < dp2[j]+1) {
                  dp2[i] = dp2[j]+1;
                  dp1[i].clear();
                  dp1[i].pb(j);
                } else if (dp2[i] == dp2[j]+1) {
                  dp1[i].pb(j);
                }
              }
            }
          }

          s.insert(arr[j]);
        }

        result = max(result, dp2[i]);
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.lenLongestFibSubseq(arr) << endl;

  return 0;
}