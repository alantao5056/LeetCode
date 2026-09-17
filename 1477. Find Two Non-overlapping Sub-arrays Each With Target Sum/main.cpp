#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int N = arr.size();
    vector<int> pref(N+1);
    map<int, int> m1;
    m1[0] = 0;
    vector<pii> ints;
    map<int, int> freq;
    for (int i = 1; i <= N; i++) {
      pref[i] = pref[i-1] + arr[i-1];
      if (m1.find(pref[i]-target) != m1.end()) {
        ints.push_back({m1[pref[i]-target]+1, i});
        freq[ints.rbegin()->second - ints.rbegin()->first + 1]++;
      }
      m1[pref[i]] = i;
    }

    sort(ints.begin(), ints.end());

    int j = 0;

    int ans = INT_MAX;
    for (int i = 0; i < ints.size(); i++) {
      while (j < ints.size() && ints[j].first <= ints[i].second) {
        int len = ints[j].second - ints[j].first + 1;
        freq[len]--;
        if (freq[len] == 0) {
          freq.erase(len);
        }
        j++;
      }

      if (freq.size() == 0) break;
      ans = min(ans, ints[i].second-ints[i].first+1 + freq.begin()->first);
    }
    
    return ans == INT_MAX ? -1 : ans;
  }
};

int main() {
  int N, target;
  cin >> N >> target;
  
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.minSumOfLengths(arr, target) << endl;

  return 0;
}
