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
    int right = 0;
    map<int, int> freq;
    int tot = 0;

    int left = 0;
    int res = 1;
    for (int cur = nums[0]; cur <= 100000; cur++) {
      // update right
      while (right < nums.size() && nums[right] <= cur+k) {
        freq[nums[right]]++;
        right++;
        tot++;
      }

      // update left
      while (left < nums.size() && nums[left] < cur-k) {
        freq[nums[left]]--;
        left++;
        tot--;
      }

      res = max(res, freq[cur] + min(numOperations, tot-freq[cur]));
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