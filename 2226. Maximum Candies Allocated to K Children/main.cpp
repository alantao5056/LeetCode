#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();
    ll low = 0;
    ll high = 1e12;
    
    while (low < high) { // notice we do not compare element at mid with our target
      int mid = low + (high - low + 1) / 2;

      ll s = 0;
      for (int c : candies) {
        s += c/mid;
      }

      if (s >= k)
        low = mid;
      else
        high = mid - 1;
    }

    return low;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N;
  ll M;
  cin >> N >> M;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  Solution s;
  cout << s.maximumCandies(arr, M) << endl;

  return 0;
}