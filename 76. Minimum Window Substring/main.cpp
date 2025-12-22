#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
  int toi(char c) {
    int x = c;
    if (x < 97) return x-65;
    return x-71;
  }

  int start = -1;

  bool check(string s, int len, vector<int>& tf) {
    vector<int> f(52);

    for (int i = 0; i < len; i++) {
      f[toi(s[i])]++;
    }

    for (int j = len; j <= s.size(); j++) {
      bool works = true;
      for (int i = 0; i < 52; i++) {
        if (f[i] < tf[i]) {
          works = false;
          break;
        }
      }

      if (works) {
        start = j-len;
        return true;
      }

      f[toi(s[j-len])]--;
      if (j != s.size()) {
        f[toi(s[j])]++;
      }
    }

    return false;
  }

public:
  string minWindow(string s, string t) {
    int n = s.size();
    vector<int> tf(52);
    for (int i = 0; i < t.size(); i++) {
      tf[toi(t[i])]++;
    }

    int low = 1;
    int high = n;
    
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (check(s, mid, tf))
        high = mid;
      else
        low = mid + 1;
    }

    if (check(s, low, tf)) {
      return s.substr(start, low);
    }
    return "";
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s, t; cin >> s >> t;
  Solution sol;
  cout << sol.minWindow(s, t) << endl;  

  return 0;
}