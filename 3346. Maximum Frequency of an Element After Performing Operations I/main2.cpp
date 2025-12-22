#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    
    // left based
    int r = 0;
    int res = 1;
    map<int, int> freq;
    for (int l = 0; l < nums.size(); l++) {
      while (r < nums.size() && nums[r] <= (ll)nums[l] + 2*k) {
        freq[nums[r]]++;
        r++;
      }

      res = max(res, freq[(ll)nums[l]+k] + min(numOperations, r-l-freq[(ll)nums[l]+k]));

      freq[nums[l]]--;
    }

    // center based
    freq.clear();
    int left = 0;
    int right = 0;

    for (int i = 0; i < nums.size(); i++) {
      // update right
      while (right < nums.size() && nums[right] <= (ll)nums[i]+k) {
        freq[nums[right]]++;
        right++;
      }

      // update left
      while (left < nums.size() && nums[left] < nums[i]-k) {
        freq[nums[left]]--;
        left++;
      }

      res = max(res, freq[nums[i]] + min(numOperations, right-left-freq[nums[i]]));
    }

    return res;
  }
};



int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, K, O;
  cin >> N >> K >> O;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.maxFrequency(arr, K, O) << endl;  

  return 0;
}