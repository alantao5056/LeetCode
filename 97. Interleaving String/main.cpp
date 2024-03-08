#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string s1, s2, s3;
  bool recursive(int p1, int p2, int p3) {
    for (int i = p3; i < s3.size(); i++) {
      if (p1 < s1.size() && s1[p1] == s3[i]) {
        if (p2 < s2.size() && s2[p2] == s3[i]) {
          if (recursive(p1+1, p2, i+1) || recursive(p1, p2+1, i+1)) {
            return true;
          } else {
            return false;
          }
        }
        p1++;
      }
      else if (p2 < s2.size() && s2[p2] == s3[i]) {
        p2++;
      }
      else {
        return false;
      }
    }
    
    return true;
  }

  bool isInterleave(string s1, string s2, string s3) {
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;

    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    
    return recursive(0, 0, 0);
  }
};

int main() {
  freopen("interleaving.in", "r", stdin);
  freopen("interleaving.out", "w", stdout);

  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  Solution s;
  cout << s.isInterleave(s1, s2, s3) << endl;

  return 0;
}