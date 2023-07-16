#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int maxTurbulenceSize(vector<int>& arr) {
      int n = arr.size();
      if (n == 1) {
        return 1;
      }
      int direction = 0; // 1 is up; 2 is down
      int cur = 0;
      int result = 1;
      for (int i = 0; i < n-1; i++) {
        cur++;
        if (arr[i+1] == arr[i]) {
          result = max(result, cur);
          cur = 0;
          continue;
        }
        if (arr[i+1] > arr[i]) { // up
          if (direction==2 || direction == 0) {
            direction = 1;
          } else {
            result = max(result, cur);
            cur = 1;
          }
        } else { // down
          if (direction==1 || direction == 0) {
            direction = 2;
          } else {
            result = max(result, cur);
            cur = 1;
          }
        }
      }
      return max(result, cur+1);
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.maxTurbulenceSize(arr) << endl;

  return 0;
}