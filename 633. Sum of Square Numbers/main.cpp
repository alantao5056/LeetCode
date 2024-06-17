#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool judgeSquareSum(int c) {
    int root = sqrt(c);

    set<int> squares;
    for (int i = 0; i <= root; i++) {
      squares.insert(i*i);
    }

    for (int i = 0; i <= root; i++) {
      if (squares.find(c-i*i) != squares.end()) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  
  int c;
  cin >> c;

  Solution s;
  cout << s.judgeSquareSum(c) << endl;

  return 0;
}