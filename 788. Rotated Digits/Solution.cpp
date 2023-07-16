#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int rotatedDigits(int n) {
      int result = 0;
      for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        string after = "";
        bool invalid = false;
        for (char c : s) {
          int digit = int(c-'0');
          if (digit == 1) {
            after += '1';
          } else if (digit == 2) {
            after += '5';
          } else if (digit == 3) {
            invalid = true;
            break;
          } else if (digit == 4) {
            invalid = true;
            break;
          } else if (digit == 5) {
            after += '2';
          } else if (digit == 6) {
            after += '9';
          } else if (digit == 7) {
            invalid = true;
            break;
          } else if (digit == 8) {
            after += '8';
          } else if (digit == 9) {
            after += '6';
          } else {
            after += '0';
          }
        }

        if (invalid) continue;
        if (stoi(after) != i) result++;
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  Solution s;
  cout << s.rotatedDigits(N) << endl;

  return 0;
}