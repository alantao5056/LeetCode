#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int N = 0;
  vector<vector<TreeNode*>> depths;
  vector<vector<int>> dists;
  vector<pair<int, bool>> par; // false = left; true = right;
  void init(TreeNode* t, int depth) {
    int pn = N;
    t->val = N++;
    depths[depth].push_back(t);
    if (t->left != nullptr) {
      par.push_back({pn, false});
      init(t->left, depth+1);
    }
    if (t->right != nullptr) {
      par.push_back({pn, true});
      init(t->right, depth+1);
    }
  }

  int cd(int a, int b) {
    if (a > b) swap(a, b);
    if (dists[a][b] != 0) {
      return dists[a][b];
    }
    if (a == b) {
      dists[a][b] = 1;
      return 1;
    }

    int pdist = cd(par[a].first, par[b].first)-2;
    int dist = 2;
    if (pdist != -1) {
      dist += !par[a].second;
      dist += par[b].second;
      dist += pdist*2;
    }

    dists[a][b] = dist;
    return dist;
  }

  int widthOfBinaryTree(TreeNode* root) {
    depths.resize(3001, vector<TreeNode*>());
    par.push_back({0, false});
    init(root, 0);
    dists.resize(N, vector<int>(N));

    int ans = 1;
    for (int i = 0; i < 3001; i++) {
      if (depths[i].size() == 0 || depths[i].size() == 1) continue;

      int K = depths[i].size();
      for (int j = 0; j < K; j++) {
        for (int k = j+1; k < K; k++) {
          int a = depths[i][j]->val;
          int b = depths[i][k]->val;
          ans = max(ans, cd(a, b));
        }
      }
    }

    return ans;
  }
};

int main() {
  // freopen("0.in", "r", stdin);
  // freopen("0.out", "w", stdout);

  int N; cin >> N;

  vector<TreeNode> nodes(N);
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;

    if (a == -1) {
      nodes[i].left = nullptr;
    } else {
      nodes[i].left = &nodes[a];
    }

    if (b == -1) {
      nodes[i].right = nullptr;
    } else {
      nodes[i].right = &nodes[b];
    }
  }

  Solution s;
  cout << s.widthOfBinaryTree(&nodes[0]) << endl;
  
  return 0;
}
