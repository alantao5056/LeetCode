#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    int n = words.size();

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
      return a.size() < b.size();
    });

    set<string> mywords;

    vector<string> ans;

    for (int i = 0; i < n; i++) {
      int m = words[i].size();

      vector<bool> dp(m+1);
      dp[0] = true;
      for (int j = 1; j <= m; j++) {
        string cur = "";
        for (int k = j; k >= 1; k--) {
          cur = words[i][k-1] + cur;
          if (mywords.find(cur) != mywords.end() && dp[k-1]) {
            dp[j] = true;
            break;
          }
        }
      }

      if (dp[m]) {
        ans.push_back(words[i]);
      }

      mywords.insert(words[i]);
    }

    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;

  vector<string> words(N);
  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }

  Solution s;
  vector<string> res = s.findAllConcatenatedWordsInADict(words);

  for (string w : res) {
    cout << w << endl;
  }

  return 0;
}