#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
  bool check(int n, vector<int>& batteries, long long time) {
    long long curN = 0;
    long long curTime = 0;
    for (int b : batteries) {
      if (b >= time) {
        curN++;
      } else {
        if (curTime + b >= time) {
          curN++;
          curTime = curTime + b - time;
        } else {
          curTime += b;
        }
      }
    }

    if (curN >= n) {
      return true;
    }
    return false;
  }

  long long maxRunTime(int n, vector<int>& batteries) {
    int B = batteries.size();

    sort(batteries.begin(), batteries.end(), greater<>());
    
    long long low = 0;
    long long high = 1e14;
    
    while (low < high) {
      long long mid = low + (high - low + 1) / 2;
      if (check(n, batteries, mid))
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

  int N, B; cin >> N >> B;

  vector<int> batteries(B);
  for (int i = 0; i < B; i++) {
    cin >> batteries[i];
  }

  Solution s;

  cout << s.maxRunTime(N, batteries) << endl;

  return 0;
}