#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int id;
  int lc;
  vector<Node*> nbs;
  Node* parent;
};

void nbs(Node* cur) {
  for (Node* n : cur->nbs) {
    if (n != cur->parent) {
      n->parent = cur;
      nbs(n);
    }
  }
}

int lc(Node* cur) {
  int m = 0;
  for (Node* n : cur->nbs) {
    if (n == cur->parent) continue;
    m = max(m, lc(n));
  }
  cur->lc = m + 1;
  return cur->lc;
}

vector<int> result;

void dfs(Node* cur, int steps, int target) {
  if (steps == 0) {
    result.push_back(cur->id);
    return;
  }
  for (Node* n : cur->nbs) {
    if (n == cur->parent) continue;
    if (n->lc == target) {
      dfs(n, steps-1, target-1);
    }
  }
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<Node> nodes(n);
      for (int i = 0; i < n; i++) {
        nodes[i].id = i;
      }

      for (int i = 0; i < n-1; i++) {
        nodes[edges[i][0]].nbs.push_back(&nodes[edges[i][1]]);
        nodes[edges[i][1]].nbs.push_back(&nodes[edges[i][0]]);
      }

      nodes[0].parent = NULL;
      nbs(&nodes[0]);

      lc(&nodes[0]);

      int maxVal = 0;
      int maxVal2 = 0;

      for (int i = 0; i < nodes[0].nbs.size(); i++) {
        int val = nodes[0].nbs[i]->lc;
        if (val > maxVal) {
          maxVal2 = maxVal;
          maxVal = val;
        } else if (val > maxVal2) {
          maxVal2 = val;
        }
      }

      if (maxVal == maxVal2) return vector<int>{0};

      int total = (maxVal + maxVal2) + 1;
      int depth = total/2 - maxVal2;

      dfs(&nodes[0], depth, maxVal);
      if (total%2 == 0) {
        dfs(&nodes[0], depth-1, maxVal);
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n;
  cin >> n;
  
  vector<vector<int>> edges(n-1, vector<int>(2));
  for (int i = 0; i < n-1; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  Solution s;
  s.findMinHeightTrees(n, edges);
  
  for (int r : result) {
    cout << r << endl;
  }
  
  return 0;
}