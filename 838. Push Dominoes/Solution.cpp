#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    string pushDominoes(string dominoes) {
      int n = dominoes.size();

      string result(n, '.');
      int prev = 0;
      bool right = true;
      for (int i = 0; i < n; i++) {
        if (dominoes[i] == '.') continue;
        if (right) {
          if (dominoes[i] == 'R') {
            right = false;
          } else {
            for (int j = i; j >= prev; j--) {
              result[j] = 'L';
            }
          }
        } else {
          if (dominoes[i] == 'L') {
            int mid = (prev+i)/2;
            for (int j = i; j >= prev; j--) {
              if (j > mid) {
                result[j] = 'L';
              } else{
                result[j] = 'R';
              }
            }

            if ((prev+i)%2 == 0) {
              result[mid] = '.';
            }
            right = true;
          } else {
            for (int j = i; j >= prev; j--) {
              result[j] = 'R';
            }
          }
        }

        prev = i;
      }

      if (!right && (dominoes[0] == 'R' || prev != 0)) {
        for (int i = prev; i < n; i++) {
          result[i] = 'R';
        }
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string dominoes;
  cin >> dominoes;

  Solution s;
  cout << s.pushDominoes(dominoes) << endl;

  return 0;
}