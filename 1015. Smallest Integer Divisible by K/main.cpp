#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    if (k%2 == 0 || k%5 == 0) return -1;

    // 1, 3, 7, 9
    int ans = 0;
    ll cur = 0;
    while (true) {
      int need = (11-cur%10)%10;
      int mult = -1;
      for (int i = 1; i < 10; i++) {
        if (((k%10)*(i))%10 == need) {
          mult = i;
          break;
        }
      }

      if (mult == -1) return -1;

      cur += k*mult;

      while (cur % 10 == 1) {
        cur /= 10;
        ans++;
      }

      if (cur == 0) {
        return ans;
        break;
      }
    }
  }
};

int main() {
  int k; cin >> k;

  Solution s;
  cout << s.smallestRepunitDivByK(k) << endl;

  return 0;
}
