#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, E;

class Compare {
public:
  bool operator() (const pair<int, int>& a, const pair<int, int>& b)
  {
    double aa = (double) (a.first+1) / (a.second+1) - (double) a.first / a.second;
    double bb = (double) (b.first+1) / (b.second+1) - (double) b.first / b.second;
    return aa < bb;
  }
};

class Solution {
public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    int n = classes.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    double k = 0;
    for (int i = 0; i < classes.size(); i++) {
      pq.push({classes[i][0], classes[i][1]});
    }

    for (int i = 0; i < extraStudents; i++) {
      pair<int, int> cur = pq.top();
      pq.pop();

      pq.push({cur.first + 1, cur.second + 1});
    }

    while (!pq.empty()) {
      k += (double) pq.top().first / pq.top().second; pq.pop();
    }

    return k / n;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> E;
  vector<vector<int>> classes(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> classes[i][0] >> classes[i][1];
  }

  Solution s;
  cout << s.maxAverageRatio(classes, E) << endl;

  return 0;
}