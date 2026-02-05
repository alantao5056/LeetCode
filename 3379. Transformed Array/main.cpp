#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> constructTransformedArray(vector<int>& nums) {
    int N = nums.size();

    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
      if (nums[i] < 0) {
        int j = (i+N*100000+nums[i])%N;
        ans[i] = nums[j];
      } else if (nums[i] > 0) {
        ans[i] = nums[(i+nums[i])%N];
      } else {
        ans[i] = nums[i];
      }
    }

    return ans;
  }
};

int main() {
  // freopen("0.in", "r", stdin);
  // freopen("0.out", "w", stdout);

  int N; cin >> N;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  vector<int> ans = s.constructTransformedArray(arr);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}

