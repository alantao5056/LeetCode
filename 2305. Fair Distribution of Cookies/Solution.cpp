#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, k;

class Solution {
  public:
    int distributeCookies(vector<int>& cookies, int k) {
      int n = cookies.size();

      vector<int> base(n);
      int result = INT_MAX;
      for (int i = 0; i < pow(k, n+1)-1; i++) {
        vector<int> values(k);
        for (int j = 0; j < n; j++) {
          values[base[j]] += cookies[j];
        }

        int maxTot = 0;
        for (int j = 0; j < k; j++) {
          maxTot = max(maxTot, values[j]);
        }

        result = min(result, maxTot);
        addOne(base, k);
      }

      return result;
    }

    void addOne(vector<int>& base, int k) {
      int i = base.size()-1;
      for (; i >= 0; i--) {
        if (base[i] != k-1) {
          base[i]++;
          break;
        }
      }

      for (int j = i+1; j < base.size(); j++) {
        base[j] = 0;
      }
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> k;
  vector<int> cookies(N);
  for (int i = 0; i < N; i++) {
    cin >> cookies[i];
  }

  Solution s;
  cout << s.distributeCookies(cookies, k) << endl;

  return 0;
}