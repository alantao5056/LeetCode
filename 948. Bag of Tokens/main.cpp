#include <bits/stdc++.h>

using namespace std;

int N;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      sort(tokens.begin(), tokens.end());

      N = tokens.size();

      int left = 0;
      int right = N-1;
      int score = 0;
      int maxScore = 0;
      int curP = power;

      while (left <= right) {
        if (tokens[left] <= curP) {
          curP -= tokens[left];
          score++;
          left++;
        } else if (score > 0) {
          curP += tokens[right];
          score--;
          right--;
        } else {
          break;
        }
        maxScore = max(maxScore, score);
      } 
      return maxScore;
    }
};

int power;

int main() {
  freopen("tokens.in", "r", stdin);
  freopen("tokens.out", "w", stdout);

  cin >> N;
  cin >> power;

  vector<int> tokens(N);
  for (int i = 0; i < N; i++) {
    cin >> tokens[i];
  }

  Solution s;

  cout << s.bagOfTokensScore(tokens, power) << endl;

  return 0;
}