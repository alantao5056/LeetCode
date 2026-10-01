#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool validUtf8(vector<int>& data) {
    int N = data.size();

    int i = 0;

    while (i < N) {
      int bit = 1 << 7;
      int cnt = 0;
      for (int j = 0; j < 8; j++) {
        if (!(data[i] & bit)) {
          break;
        }
        cnt++;
        bit = bit >> 1;
      }
      
      if (cnt > 4) return false;

      i++;
      if (cnt == 0) {
        continue;
      }
      if (cnt == 1) return false;

      for (int k = 0; k < cnt-1; k++) {
        if (i >= N) return false;
        if (!(data[i] & (1 << 7)) || (data[i] & (1 << 6))) {
          return false;
        }
        i++;
      }
    }

    return true;
  }
};

int main() {
  // freopen("0.in", "r", stdin);

  int N; cin >> N;
  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.validUtf8(arr) << endl;

  return 0;
}
