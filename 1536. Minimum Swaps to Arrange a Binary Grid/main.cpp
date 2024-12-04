#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = n-1; j >= 0; j--) {
        if (grid[i][j] == 1) break;
        cur++;
      }

      arr[i] = cur;
    }

    int total = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
      swapped = false;
      bool flag;
      for (int j = 0; j < n - i - 1; j++) {
        flag = true;
        if (arr[j] < arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          swapped = true;
          total++;
        }

        for (int i = 0; i < n; i++) {
          if (arr[i] < n-i-1) {
            flag = false;
            break;
          }
        }
        if (flag) break;
      }

      if (!swapped || flag) break;
    }

    for (int i = 0; i < n; i++) {
      if (arr[i] < n-i-1) {
        return -1;
      }
    }

    return total;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n; cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  Solution s;
  cout << s.minSwaps(grid) << endl;

  return 0;
}