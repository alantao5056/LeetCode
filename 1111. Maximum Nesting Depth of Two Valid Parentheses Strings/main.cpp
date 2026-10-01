#include <bits/stdc++.h>
#include <cmath>
#include <cstdarg>

using namespace std;

class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    int N = seq.size();

    int cnt = 0;
    vector<int> dep(N);
    int m = 0;
    for (int i = 0; i < N; i++) {
      if (seq[i] == '(') {
        cnt++;
        dep[i] = cnt;
        m = max(m, cnt);
      } else {
        dep[i] = cnt;
        cnt--;
      }
    }

    vector<int> res(N);
    for (int i = 0; i < N; i++) {
      if (dep[i] >= (m+2)/2) {
        res[i] = 1;
      }
    }
    
    return res;
  }
};

int main() {
  freopen("0.in", "r", stdin);

  string str;

  Solution s;

  vector<int> res = s.maxDepthAfterSplit(str);
  for (int r : res) {
    cout << r << endl;
  }

  return 0;
}
