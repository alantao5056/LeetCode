#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    bool PredictTheWinner(vector<int>& nums) {
      int n = nums.size();
      pii result = recursive(nums, {0, 0}, 0, n-1, true);
      return result.first - result.second >= 0;
    }

    pii recursive(vector<int>& nums, pii score, int i, int j, bool turn) {
      if (i == j) {
        // one choice
        if (turn) {
          return {score.first + nums[i], score.second};
        } else {
          return {score.first, score.second + nums[j]};
        }
      }

      if (turn) {
        pii a = recursive(nums, {score.first + nums[i], score.second}, i+1, j, false);
        int diffA = a.first - a.second;
        pii b = recursive(nums, {score.first + nums[j], score.second}, i, j-1, false);
        int diffB = b.first - b.second;

        return diffA > diffB ? a : b;
      } else {
        pii a = recursive(nums, {score.first, score.second + nums[i]}, i+1, j, true);
        int diffA = a.first - a.second;
        pii b = recursive(nums, {score.first, score.second + nums[j]}, i, j-1, true);
        int diffB = b.first - b.second;

        return diffA < diffB ? a : b;
      }
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  Solution s;
  cout << s.PredictTheWinner(nums) << endl;

  return 0;
}