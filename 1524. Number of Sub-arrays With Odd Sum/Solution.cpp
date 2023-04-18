#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int numOfSubarrays(vector<int>& arr) {
      int n = arr.size();
      int MOD = 1000000007;
      vector<int> dp(n+1);
      dp[0] = arr[0] % 2 == 1 ? 1 : 0;

      for (int i = 1; i < n; i++) {
        if (arr[i] % 2 == 0) { // even
          dp[i] = dp[i-1];
        } else { // odd
          dp[i] = i-dp[i-1]+1;
        }
      }

      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += dp[i];
        sum %= MOD;
      }
      return sum;
    }
};  

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.numOfSubarrays(arr) << endl;

  return 0;
}