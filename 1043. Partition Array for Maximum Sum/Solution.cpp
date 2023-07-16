#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N, K;

class Solution {
  public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      arr.insert(arr.begin(), 0);
      vector<int> dp(n+1);
      for(int i = 1; i <= n; i++) {
        int curMax = 0;
        for (int j = 0; j < k; j++) {
          curMax = max(curMax, arr[i-j]);
          if (i-j-1 < 0) {
            break;
          }
          dp[i] = max(dp[i], dp[i-j-1] + curMax * (j+1));
        }
      }

      return dp[n];
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N >> K;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.maxSumAfterPartitioning(arr, K) << endl;


  return 0;
}