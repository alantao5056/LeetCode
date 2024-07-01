#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  vector<int> a;
  vector<int> b;
  vector<int> ab;
};

struct less_than_key {
  inline bool operator() (const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
      return a[1] < b[1];
    }
    if (a[2] != b[2]) {
      return a[2] < b[2];
    }

    return a[0] > b[0];
  }
};

class Solution {
public:
    int m;
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      m = edges.size();
      vector<Node> nodes(n+1);

      sort(edges.begin(), edges.end(), less_than_key());

      int a, b, c = -1;
      for (int i = 0; i < m; i++) {
        if (edges[i][1] == b && edges[i][2] == c && a == 3) {
          continue;
        }

        if (edges[i][0] == 1) {
          nodes[edges[i][1]].a.push_back(edges[i][2]);
          nodes[edges[i][2]].a.push_back(edges[i][1]);
        } else if (edges[i][0] == 2) {
          nodes[edges[i][1]].b.push_back(edges[i][2]);
          nodes[edges[i][2]].b.push_back(edges[i][1]);
        } else {
          nodes[edges[i][1]].ab.push_back(edges[i][2]);
          nodes[edges[i][2]].ab.push_back(edges[i][1]);
        }

        a = edges[i][0];
        b = edges[i][1];
        c = edges[i][2];
      }

      // alice check
      deque<int> q;
      q.push_back(1);
      vector<bool> visited(n+1);
      visited[1] = true;
      while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        for (int i : nodes[cur].a) {
          if (!visited[i]) {
            visited[i] = true;
            q.push_back(i);
          }
        }

        for (int i : nodes[cur].ab) {
          if (!visited[i]) {
            visited[i] = true;
            q.push_back(i);
          }
        }
      }

      for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
          return -1;
        }
        visited[i] = false;
      }

      // bob check
      q.push_back(1);
      visited[1] = true;
      while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        for (int i : nodes[cur].b) {
          if (!visited[i]) {
            visited[i] = true;
            q.push_back(i);
          }
        }

        for (int i : nodes[cur].ab) {
          if (!visited[i]) {
            visited[i] = true;
            q.push_back(i);
          }
        }
      }

      for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
          return -1;
        }
        visited[i] = false;
      }

      int keep = 0;
      int components = 0;
      for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        components++;
        int s = 0;
        visited[i] = true;
        q.push_back(i);

        while (!q.empty()) {
          int cur = q.front();
          q.pop_front();

          s++;

          for (int j : nodes[cur].ab) {
            if (!visited[j]) {
              visited[j] = true;
              q.push_back(j);
            }
          }
        }

        keep += s-1;
      }

      return m - ((components -1)*2 + keep);
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n; cin >> n;
  int m; cin >> m;
  vector<vector<int>> edges(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> edges[i][j];
    }
  }

  Solution s;
  cout << s.maxNumEdgesToRemove(n, edges) << endl;

  return 0;
}