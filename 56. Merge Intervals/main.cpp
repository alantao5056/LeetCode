#include <bits/stdc++.h>

using namespace std;

int N;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    N = intervals.size();
    
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < N; i++) {
      if (intervals[i][0] > end) {
        // new
        result.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      } else {
        end = max(end, intervals[i][1]);
      }
    }

    result.push_back({start, end});

    return result;
  }
};

int main() {
  freopen("merge.in", "r", stdin);
  freopen("merge.out", "w", stdout);

  cin >> N;

  vector<vector<int>> intervals(N, vector<int>(2));

  for (int i = 0; i < N; i++) {
    cin >> intervals[i][0];
    cin >> intervals[i][1]; 
  }

  Solution s;
  vector<vector<int>> result = s.merge(intervals);
  for (vector<int> r : result) {
    cout << r[0] << " " << r[1] << endl;
  }


  return 0;
}