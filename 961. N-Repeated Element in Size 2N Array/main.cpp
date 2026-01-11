#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int repeatedNTimes(vector<int>& nums) {
    int N = nums.size();

    map<int, int> m;
    for (int n : nums) {
      m[n]++;
    }

    for (auto const& [key, val] : m) {
      if (val == N/2) {
        return key;
      }
    }

    return -1;
  }
};
