#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    int n = nums.size();

    stack<int> s;
    for (int i = 0; i < n; i++) {
      int val = nums[i];

      while (s.size() > 0 && gcd(s.top(), val) > 1) {
        val = lcm(s.top(), val);
        s.pop();
      }

      s.push(val);
    }

    int m = s.size();
    vector<int> res(m);

    for (int i = m-1; i >= 0; i--) {
      res[i] = s.top();
      s.pop();
    }


    return res;
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
  vector<int> res = s.replaceNonCoprimes(arr);

  for (int r : res) {
    cout << r << endl;
  }

  return 0;
}