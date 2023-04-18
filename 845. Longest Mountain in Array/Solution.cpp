#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int longestMountain(vector<int>& arr) {
      int n = arr.size();
      vector<int> arr2(n);
      arr2[0] = 0;
      for (int i = 1; i < n; i++) {
        arr2[i] = arr[i] > arr[i-1] ? 1 : arr[i] < arr[i-1] ? -1 : 0;
      }
      
      int result = 0;
      int curLen = 0;
      // for (int i = 0; i < n; i++) {
      //   if (arr2[i] == -1) {
      //     curLen++;
      //   } else {
      //     result = max(result, curLen);
      //     curLen = 0;
      //   }
      // }
      // result = max(result, curLen);
      // curLen = 0;
      bool one = true;
      for (int i = 0; i < n; i++) {
        if (one) {
          if (arr2[i] == 1) {
            curLen++;
          } else if (arr2[i] == -1) {
            if (curLen > 0) {
              one = false;
              i--;
            }
          } else {
            curLen = 0;
          }
        } else {
          if (arr2[i] == -1) {
            curLen++;
          } else {
            result = max(result, curLen);
            curLen = 0;
            one = true;
            if (arr2[i] == 1) {
              i--;
            }
          }
        }
      }
      if (!one) {
        result = max(result, curLen);
      }

      result++;
      return result >= 3 ? result : 0;
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
  cout << s.longestMountain(arr) << endl;

  return 0;
}