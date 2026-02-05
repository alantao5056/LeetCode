#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int N = a.size(); int M = b.size();

    vector<bool> arr;
    bool carry = false;
    for (int i = 0; i < max(N, M); i++) {
      int ai = N-i-1;
      int bi = M-i-1;

      int s = carry;
      if (ai >= 0) {
        s += a[ai] == '1';
      }
      if (bi >= 0) {
        s += b[bi] == '1';
      }

      carry = s/2;
      arr.push_back(s%2);
    }

    if (carry) {
      arr.push_back(true);
    }

    string ans;
    for (int i = arr.size()-1; i >= 0; i--) {
      ans += arr[i] ? '1' : '0';
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  string a; string b; cin >> a >> b;

  Solution s;
  cout << s.addBinary(a, b) << endl;

  return 0;
}
