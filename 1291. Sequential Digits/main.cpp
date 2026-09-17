#include <bits/stdc++.h>

using namespace std;
class Solution {
    int getd(int x) {
        int d = 0;
        while (x > 0) {
            x /= 10;
            d++;
        }
        return d;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int l = getd(low);
        int r = getd(high);
        vector<int> ans;
        
        for (int d = l; d <= r; d++) {
            string s;
            for (int i = 0; i < d; i++) {
                s += ('1' + i);
            }

            while (s[d-1] != ':') {
                int si = stoi(s);
                if (si >= low && si <= high) {
                    ans.push_back(si);
                }

                for (int i = 0; i < d; i++) {
                    s[i]++;
                }
            }
        }

        return ans;
    }
};

int main() {
  freopen("0.in", "r", stdin);
  freopen("0.out", "w", stdout);

  int low, high;
  cin >> low >> high;

  Solution s;
  vector<int> ans = s.sequentialDigits(low, high);

  for (int a : ans) {
    cout << a << endl;
  }

  return 0;
}
