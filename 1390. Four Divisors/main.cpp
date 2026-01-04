#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
using ll = long long;

class Solution {
  public:
    int sumFourDivisors(vector<int>& nums) {
      int N = nums.size();
      int C = 1e5;

      vector<bool> sieve(C+1, true);
      vector<ll> primes;
      for (int i = 2; i <= C; i++) {
        if (!sieve[i]) continue;
        primes.push_back(i);

        for (int j = i*2; j <= C; j+=i) {
          sieve[j] = false;
        }
      }

      vector<ll> sieve2(C+1, -1);
      for (int i = 0; i < primes.size(); i++) {
        ll res = pow(primes[i], 3);
        if (res <= C) {
          sieve2[res] = primes[i] + primes[i]*primes[i] +res+1;
        }

        for (int j = i+1; j < primes.size(); j++) {
          res = primes[i] * primes[j]; 
          if (res > C) {
            break;
          }

          sieve2[res] = res+1+primes[i] + primes[j];
        }
      }

      ll ans = 0;
      for (int n : nums) {
        if (sieve2[n] != -1) {
          ans += sieve2[n];
        }
      }

      return ans;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N; cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.sumFourDivisors(nums) << endl;

  return 0;
}
