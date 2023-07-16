#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, P;

class Solution {
  public:
    int n;
    bool check(vector<int>& nums, int p, int diff) {
      int count = 0;
      for (int i = 0; i < n-1; i++) {
        int curDiff = nums[i+1] - nums[i];

        if (curDiff <= diff) {
          count++;
          i++;
        }
      }

      return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
      n = nums.size();

      sort(nums.begin(), nums.end());

      if (p == 0) {
        return 0;
      }

      // binary search
      int low = 0;
      int high = 1000000000;
      
      while (low < high) { // notice we do not compare element at mid with our target
        int mid = low + (high - low) / 2;
        if (!check(nums, p, mid))
          low = mid + 1;
        else
          high = mid;
      }

      return low;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> P;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.minimizeMax(nums, P) << endl;

  return 0;
}