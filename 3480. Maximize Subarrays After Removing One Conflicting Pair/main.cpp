#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        vector<vector<pair<int, int>>> ab;
        for (int i = 0; i < m; i++) {
            if (conflictingPairs[i][0] > conflictingPairs[i][1]) {
                swap(conflictingPairs[i][0], conflictingPairs[i][1]);
            }
        }

        sort(conflictingPairs.begin(), conflictingPairs.end());

        for (int i = 0; i < m; i++) {
            ab[conflictingPairs[i][0]].push_back({conflictingPairs[i][1], i});
        }

        vector<long long> adds(m);

        set<pair<int, int>> s;
        s.insert({n+1, -1});
        int cp = 0;
        int e = 1;
        long long res = 0;

        for (int i = 1; i <= n; i++) {
            while (e < s.begin()->first) {
                while (cp < m && conflictingPairs[cp][0] == e) {
                    s.insert({conflictingPairs[cp][1], cp});
                    cp++;
                }
                e++;
            }
            // e = 1+end

            res += e-i;

            int one = e;
            int block = s.begin()->first;
            int blockcp = s.begin()->second;
            if (block == n+1) {
                continue;
            }
            s.erase(s.begin());

            set<int> temp;
            temp.insert(n+1);
            int cp2 = cp;
            while (e < *temp.begin() && e < s.begin()->first) {
                while (cp2 < m && conflictingPairs[cp2][0] == e) {
                    temp.insert(conflictingPairs[cp2][1]);
                    cp2++;
                }
                e++;
            }

            adds[blockcp] += e-one;
            s.insert({block,blockcp});

            e = one;

            for (auto a : ab[i]) {
                s.erase(a);
            }
        }

        cout << res << endl;

        long long lol = 0;
        for (long long a : adds) {
            lol = max(lol, a);
        }

        return res + lol;
    }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n, m; cin >> n >> m;

  vector<vector<int>> cps(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> cps[i][0] >> cps[i][1];
  }

  Solution s;
  cout << s.maxSubarrays(n, cps) << endl;

  return 0;
}
