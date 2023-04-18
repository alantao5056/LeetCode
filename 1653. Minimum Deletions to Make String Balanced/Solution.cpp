#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string S;

class Solution {
  public:
    int minimumDeletions(string s) {
      int n = s.size();
      vector<int> prefix(n);
      int temp = 0;
      for (int i = 0; i < n; i++) {
        temp += s[i] == 'b' ? 1 : 0;
        prefix[i] = temp;
      }

      vector<int> prefix2(n);
      temp = 0;
      for (int i = n-1; i >= 0; i--) {
        temp += s[i] == 'a' ? 1 : 0;
        prefix2[i] = temp;
      }

      int result = min(prefix[n-1], prefix2[0]);
      for (int i = 0; i < n-1; i++) {
        result = min(result, prefix[i] + prefix2[i+1]);
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> S;
  Solution s;
  cout << s.minimumDeletions(S) << endl;

  return 0;
}