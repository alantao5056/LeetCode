#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
      int n = basket1.size();
      int minFruit = INT_MAX;
      map<int, int> total;
      for (int i = 0; i < n; i++) {
        total[basket1[i]]++;
        total[basket2[i]]++;
        minFruit = min(minFruit, min(basket1[i], basket2[i]));
      }

      for (auto const& [key, val] : total) {
        if (val % 2 != 0) {
          // odd
          return -1;
        }
      }

      vector<int> needSwap1;
      vector<int> needSwap2;

      map<int, int> map1;
      map<int, int> map2;
      for (int i = 0; i < n; i++) {
        if (map1[basket1[i]] < total[basket1[i]]/2) {
          map1[basket1[i]]++;
        } else {
          needSwap1.pb(basket1[i]);
        }

        if (map2[basket2[i]] < total[basket2[i]]/2) {
          map2[basket2[i]]++;
        } else {
          needSwap2.pb(basket2[i]);
        }
      }

      sort(needSwap1.begin(), needSwap1.end());
      sort(needSwap2.begin(), needSwap2.end());

      ll result = 0;
      int j = 0;
      for (int i = needSwap1.size()-1; i >= 0; i--) {
        result += min(minFruit*2,  min(needSwap1[i], needSwap2[j]));
        j++;
      }

      return result;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> basket1(N);
  vector<int> basket2(N);
  
  for (int i = 0; i < N; i++) {
    cin >> basket1[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> basket2[i];
  }

  Solution s;
  cout << s.minCost(basket1, basket2) << endl;

  return 0;
}