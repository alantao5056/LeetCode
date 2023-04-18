#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string b;

class Solution {
  int MOD = 1000000007;
  public:
    int numberOfUniqueGoodSubsequences(string binary) {
      ll one = 0;
      ll zero = 0;
      bool z = false;

      for (char c : binary) {
        if (c == '0') {
          zero += one;
          zero %= MOD;
          z = true;
        } else {
          one += zero + 1;
          one %= MOD;
        }
      }
      return one + zero + z;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> b;
  Solution s;
  cout << s.numberOfUniqueGoodSubsequences(b) << endl;

  return 0;
}