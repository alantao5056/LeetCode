#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string s_;

class Solution {
  public:
    int romanToInt(string s) {
      int n = s.size();
      int result = 0;
      int cur = 0;
      while (cur < n) {
        if (s[cur] == 'I') {
          if (cur < n-1) {
            if (s[cur+1] == 'V') {
              result += 4;
              cur+=2;
            } else if (s[cur+1] == 'X') {
              result += 9;
              cur+=2;
            } else {
              result++;
              cur++;
            }
          } else {
            result++;
            cur++;
          }
        } else if (s[cur] == 'V') {
          result += 5;
          cur++;
        } else if (s[cur] == 'X') {
          if (cur < n-1) {
            if (s[cur+1] == 'L') {
              result += 40;
              cur+=2;
            } else if (s[cur+1] == 'C') {
              result += 90;
              cur+=2;
            } else {
              result += 10;
              cur++;
            }
          } else {
            result += 10;
            cur++;
          }
        } else if (s[cur] == 'L') {
          result += 50;
          cur++;
        } else if (s[cur] == 'C') {
          if (cur < n-1) {
            if (s[cur+1] == 'D') {
              result += 400;
              cur+=2;
            } else if (s[cur+1] == 'M') {
              result += 900;
              cur+=2;
            } else {
              result += 100;
              cur++;
            }
          } else {
            result += 100;
            cur++;
          }
        } else if (s[cur] == 'D') {
          result += 500;
          cur++;
        } else {
          result += 1000;
          cur++;
        }
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> s_;

  Solution s;
  cout << s.romanToInt(s_) << endl;


  return 0;
}