#include <bits/stdc++.h>

using namespace std;

int N;

class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    N = nums.size();
    
    vector<int> freq(101);
    int maxFreq = 0;

    for (int i = 0; i < N; i++) {
      freq[nums[i]]++;
      maxFreq = max(maxFreq, freq[nums[i]]);
    }

    int result = 0;
    for (int f : freq) {
      if (f == maxFreq) {
        result += f;
      }
    }
    
    return result;
  }
};

int main() {

  freopen("frequency.in", "r", stdin);
  freopen("frequency.out", "w", stdout);

  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.maxFrequencyElements(nums) << endl;

  return 0;
}