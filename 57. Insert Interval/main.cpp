#include <bits/stdc++.h>

using namespace std;

int N;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      N = intervals.size();

      vector<vector<int>> result;
      int s = newInterval[0];
      int e = newInterval[1];
      for (int i = 0; i < N; i++) {
        bool rem = false;
        if (intervals[i][0] < s && intervals[i][1] >= s) {
          s = intervals[i][0];
          rem = true;
        }
        
        if (intervals[i][0] <= e && intervals[i][1] > e) {
          e = intervals[i][1];
          rem = true;
        }

        if (intervals[i][0] >= s && intervals[i][1] <= e) {
          rem = true;
        }

        if (!rem) {
          result.push_back(intervals[i]);
        }
      }

      for (int i = 0; i < result.size(); i++) {
        if (result[i][0] > e) {
          result.insert(result.begin() + i, {s, e});
          return result;
        }
      }

      result.push_back({s, e});

      return result;
    }
};

int main() {
  freopen("interval.in", "r", stdin);
  freopen("interval.out", "w", stdout);

  cin >> N;
  vector<int> newInterval(2);
  cin >> newInterval[0] >> newInterval[1];

  vector<vector<int>> intervals(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> intervals[i][0] >> intervals[i][1];
  }

  Solution s;

  vector<vector<int>> result = s.insert(intervals, newInterval);

  for (vector<int> r : result) {
    cout << r[0] << " " << r[1] << endl;
  }
  
  return 0;
}