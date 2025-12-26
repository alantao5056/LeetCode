#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int bestClosingTime(string customers) {
    int N = customers.size();

    vector<int> suffix(N+1);
    for (int i = N-1; i>=0; i--) {
      suffix[i] = suffix[i+1];
      if (customers[i] == 'Y') {
        suffix[i]++;
      }
    }

    int minP = suffix[0];
    int ans = 0;
    int left = 0;
    for (int i = 0; i < N; i++) {
      if (customers[i] == 'N') {
        left++;
      }

      if (left + suffix[i+1] < minP) {
        minP = left + suffix[i+1];
        ans = i+1;
      }
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  
  string s; cin >> s;

  Solution sol;
  cout << sol.bestClosingTime(s) << endl;
  
  return 0;
}
