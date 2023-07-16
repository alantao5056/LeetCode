#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int M, N;

class Solution {
  public:
    int getCompatibility(vector<int>& a, vector<int>& b) {
      int count = 0;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) count++;
      }

      return count;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      int m = students.size();
      int n = students[0].size();

      // every matchup
      vector<vector<int>> combs(m, vector<int>(m));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          combs[i][j] = getCompatibility(students[i], mentors[j]);
        }
      }

      // try every perm
      vector<int> perm(m);
      for (int i = 0; i < m; i++) {
        perm[i] = i;
      }

      int maxComp = 0;
      do{
        int curComp = 0;

        for (int i = 0; i < m; i++) {
          curComp += combs[i][perm[i]];
        }

        maxComp = max(maxComp, curComp);
      } while(next_permutation(perm.begin(), perm.end()));
      return maxComp;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> M >> N;
  vector<vector<int>> students(M, vector<int>(N));
  vector<vector<int>> mentors(M, vector<int>(N));

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> students[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> mentors[i][j];
    }
  }

  Solution s;
  cout << s.maxCompatibilitySum(students, mentors) << endl;

  return 0;
}