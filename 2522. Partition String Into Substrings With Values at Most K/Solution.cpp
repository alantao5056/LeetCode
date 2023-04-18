#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string S;
int K;

class Solution {
  public:
    int minimumPartition(string s, int k) {
      // dealing with special case first
      if (k<10) {
        for (char c : s) {
          if (c-'0' > k) {
            return -1;
          }
        }
        return s.size();
      }

      string cur;
      int count = 1;
      for (char c : s) {
        cur += c;
        // check if allowed
        if (stoll(cur) > k) {
          // separate here
          count++;
          cur = c;
        }
      }
      return count;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> S >> K;
  Solution s;
  cout << s.minimumPartition(S, K) << endl;

  return 0;
}