#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int m = wordDict.size();
    set<string> words;
    for (int i = 0; i < m; i++) {
      string c = wordDict[i];
      reverse(c.begin(), c.end());
      words.insert(c);
    }

    int n = s.size();
    s = ' ' + s;
    vector<bool> dp(n+1);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      string c = "";
      for (int j = i; j > 0; j--) {
        c += s[j];
        if (words.find(c) != words.end()) {
          if (dp[j-1]) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[n];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s;
  cin >> s;
  
  int m; cin >> m;

  vector<string> d(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }

  Solution so;
  cout << so.wordBreak(s, d) << endl;

  return 0;
}