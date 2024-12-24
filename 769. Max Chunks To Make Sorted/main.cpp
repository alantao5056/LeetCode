#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();

    arr.insert(arr.begin(), -1);

    vector<int> sarr = arr;
    sort(sarr.begin(), sarr.end());

    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      vector<int> temp;
      for (int j = i; j >= 1; j--) {
        temp.push_back(arr[j]);
        sort(temp.begin(), temp.end());

        bool works = true;
        for (int k = j; k <= i; k++) {
          if (sarr[k] != temp[k-j]) {
            works = false;
            break;
          }
        }

        if (works) {
          dp[i] = max(dp[i], dp[j-1]+1);
        }
      }
    }

    return dp[n];
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.maxChunksToSorted(arr) << endl;

  return 0;
}