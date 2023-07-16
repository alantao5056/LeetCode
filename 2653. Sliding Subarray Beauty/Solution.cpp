#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, K, X;

class Solution {
  public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
      int n = nums.size();

      vector<int> result;
      map<int, int> right;
      map<int, int> left; // always have size x
      int leftSize = 0;
      // setup
      for (int i = 0; i < k; i++) {
        if (leftSize < x) {
          left[nums[i]]++;
          leftSize++;
        } else {
          if (nums[i] <= left.rbegin()->first) {
            // in left
            left[nums[i]]++;
            right[left.rbegin()->first]++;
            if (left.rbegin()->second == 1) {
              left.erase(prev(left.end()));
            } else {
              left.rbegin()->second--;
            }
          } else {
            right[nums[i]]++;
          }
        }
      }
      result.pb(left.rbegin()->first > 0 ? 0 : left.rbegin()->first);
      int l = 0;
      int r = k;
      for (; r < n; r++) {
        // remove
        if (nums[l] <= left.rbegin()->first) {
          if (left[nums[l]] == 1) {
            left.erase(nums[l]);
          } else {
            left[nums[l]]--;
          }
          if (right.size() != 0) {
            left[right.begin()->first]++;
            if (right.begin()->second == 1) {
              right.erase(right.begin()->first);
            } else {
              right.begin()->second--;
            }
          }
        } else {
          if (right[nums[l]] == 1) {
            right.erase(nums[l]);
          } else {
            right[nums[l]]--;
          }
        }
        // add
        if (x == k) {
          left[nums[r]]++;
        } else {
          if (nums[r] <= left.rbegin()->first) {
            // in left
            left[nums[r]]++;
            right[left.rbegin()->first]++;
            if (left.rbegin()->second == 1) {
              left.erase(prev(left.end()));
            } else {
              left.rbegin()->second--;
            }
          } else {
            right[nums[r]]++;
          }
        }

        result.pb(left.rbegin()->first > 0 ? 0 : left.rbegin()->first);
        l++;
      }
      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> K >> X;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  vector<int> result = s.getSubarrayBeauty(nums, K, X);
  for (int r : result) {
    cout << r << endl;
  }

  return 0;
}