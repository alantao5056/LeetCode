#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  private:
    vector<int> p;
    int n;
  public:
    int stoneGameII(vector<int>& piles) {
      n = piles.size();
      p = piles;
      return recursive(0, 1, true, {0, 0}).first;
    }

    pii recursive(int idx, int m, bool turn, pii score) {
      if (idx >= n) return score;
      if (turn) {
        int total = 0;
        pii bestScore = {0, INT_MAX};
        for (int i = idx; i < min(idx+2*m, n); i++) {
          total += p[i];
          pii s = recursive(i+1, max(m, i-idx+1), false, {score.first + total, score.second});
          if (s.first-s.second > bestScore.first-bestScore.second) {
            bestScore = s;
          }
        }

        return bestScore;
      } else {
        int total = 0;
        pii bestScore = {INT_MAX, 0};
        for (int i = idx; i < min(idx+2*m, n); i++) {
          total += p[i];
          pii s = recursive(i+1, max(m, i-idx+1), true, {score.first, score.second + total});
          if (s.second-s.first > bestScore.second-bestScore.first) {
            bestScore = s;
          }
        }

        return bestScore;
      }
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> piles(N);
  for (int i = 0; i < N; i++) {
    cin >> piles[i];
  }

  Solution s;
  cout << s.stoneGameII(piles) << endl;

  return 0;
}