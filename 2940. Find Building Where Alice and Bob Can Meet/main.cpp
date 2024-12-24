#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, Q;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Helper function to build the segment tree
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        buildTree(arr, 2 * node, start, mid);
        buildTree(arr, 2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Change this for different queries (e.g., min or max)
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // The segment tree can have at most 4 * n nodes
        buildTree(arr, 1, 0, n - 1);
    }

    // Update the value at index 'index' to 'newValue'
    void update(int index, int newValue, int node, int start, int end) {
        if (start == end) {
            tree[node] = newValue;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid) {
            update(index, newValue, 2 * node, start, mid);
        } else {
            update(index, newValue, 2 * node + 1, mid + 1, end);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Change this for different queries (e.g., min or max)
    }

    // Update the value at index 'index' to 'newValue'
    void update(int index, int newValue) {
        update(index, newValue, 1, 0, n - 1);
    }

    // Query the range [left, right]
    int query(int left, int right, int node, int start, int end) {
        if (right < start || left > end) {
            return -1; // Change this for different queries (e.g., INT_MAX for min query)
        }

        if (left <= start && right >= end) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftSum = query(left, right, 2 * node, start, mid);
        int rightSum = query(left, right, 2 * node + 1, mid + 1, end);

        return max(leftSum, rightSum); // Change this for different queries (e.g., min or max)
    }

    // Query the range [left, right]
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};


class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size();
    int q = queries.size();

    SegmentTree st(heights);

    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
      int a = queries[i][0];
      int b = queries[i][1];

      if (a > b) {
        swap(a, b);
      }

      if (a == b || heights[b] > heights[a]) {
        ans[i] = b;
        continue;
      }

      int low = b;
      int high = n - 1;
      
      while (low < high) { // notice we do not compare element at mid with our target
        int mid = low + (high - low) / 2;
        if (st.query(max(a, b), mid) > max(heights[a], heights[b]))
          high = mid;
        else
          low = mid + 1;
      }
      
      if (st.query(max(a, b), low) > max(heights[a], heights[b])) {
        ans[i] = low;
      } else {
        ans[i] = -1;
      }
    }

    return ans;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> Q;
  vector<int> heights(N);
  
  for (int i = 0; i < N; i++) {
    cin >> heights[i];
  }

  vector<vector<int>> queries(Q, vector<int>(2));
  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  Solution s;
  vector<int> ans = s.leftmostBuildingQueries(heights, queries);
  for (int a : ans) {
    cout << a << endl;
  }

  return 0;
}