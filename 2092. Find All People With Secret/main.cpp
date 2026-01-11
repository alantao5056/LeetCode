#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    int N = n;
    int M = meetings.size();

    vector<vector<pii>> adj(N);

    for (int i = 0; i < M; i++) {
      adj[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
      adj[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
    }
    adj[0].push_back({firstPerson, 0});
    adj[firstPerson].push_back({0, 0});

    vector<int> minD(N, 1e9);
    minD[0] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      pii cur = pq.top(); pq.pop();

      if (cur.first != minD[cur.second]) {
        continue;
      }

      int i = cur.second;
      for (pii e : adj[i]) {
        if (e.second < minD[i]) continue;
        if (minD[e.first] > e.second) {
          minD[e.first] = e.second;
          pq.push({e.second, e.first});
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
      if (minD[i] != 1e9) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, M, firstPerson;
  cin >> N >> M >> firstPerson;

  vector<vector<int>> meetings(M, vector<int>(3));
  for (int i = 0; i < M; i++) {
    cin >> meetings[i][0] >> meetings[i][1] >> meetings[i][2]; 
  }

  Solution s;
  vector<int> res = s.findAllPeople(N, meetings, firstPerson);

  for (int r : res) {
    cout << r << endl;
  }

  return 0;
}
  
