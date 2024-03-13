#include <bits/stdc++.h>

using namespace std;

int N;

class Solution {
public:
  int trap(vector<int>& height) {
    N = height.size();
    vector<int> sums(N+1);

    for (int i = 1; i <= N; i++) {
      sums[i] = sums[i-1] + height[i-1];
    }

    vector<pair<int, int>> prefix(N+1);
    for (int i = N-1; i >= 0; i--) {
      if (height[i] >= prefix[i+1].first) {
        prefix[i] = {height[i], i};
      } else {
        prefix[i] = prefix[i+1];
      }
    }

    int i = 0;
    int result = 0;

    while (i < N-1) {
      int curI = i;
      int curH = height[i];
      if (prefix[i+1].first >= height[i]) {
        // bigger
        i++;
        while (height[i] < curH) {
          i++;
        }

      } else {
        i = prefix[i+1].second;
      }
      // calc tot
      result += (i-curI-1) * min(height[i], curH) - (sums[i] - sums[curI+1]);
    }

    return result;
  }
};

int main() {
  freopen("rain.in", "r", stdin);
  freopen("rain.out", "w", stdout);

  cin >> N;

  vector<int> height(N);
  for (int i = 0; i < N; i++) {
    cin >> height[i];
  }

  Solution s;
  cout << s.trap(height) << endl;

  return 0;
}