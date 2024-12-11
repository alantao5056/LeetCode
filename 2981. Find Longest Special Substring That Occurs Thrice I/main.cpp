#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int n;
  bool check(string s, int mid) {
    for (int l = 0; l < 26; l++) {
      int ans = 0;
      for (int i = 0; i <= n-mid; i++) {
        bool works = true;
        for (int j = 0; j < mid; j++) {
          if (s[i+j]-'a' != l) {
            works = false;
            break;
          }
        }

        ans += works;
      }

      if (ans >= 3) return true;
    }

    return false;
  }
  
  int maximumLength(string s) {
    n = s.size();

    int low = 1;
    int high = n - 1;
    
    while (low < high) {
      int mid = low + (high - low + 1) / 2;
      if (check(s, mid))
        low = mid;
      else
        high = mid - 1;
    }

    if (!check(s, low)) {
      return -1;
    }

    return low;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s; cin >> s;

  Solution ss;
  cout << ss.maximumLength(s) << endl;

  return 0;
}