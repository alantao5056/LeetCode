#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string s;

class Solution {
  public:
    int minFlipsMonoIncr(string s) {
      int n = s.length();
      int tot1 = 0;
      vector<int> prefix(n);
      for (int i = 0; i < n; i++) {
        tot1 += s[i] == '1';
        prefix[i] = tot1;
      }

      int result = min(tot1, n-tot1);
      for (int i = 0; i < n; i++) {
        result = min(result, prefix[i] + ((n-i-1)-(tot1-prefix[i])));
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> s;
  Solution ss;
  cout << ss.minFlipsMonoIncr(s) << endl;

  return 0;
}