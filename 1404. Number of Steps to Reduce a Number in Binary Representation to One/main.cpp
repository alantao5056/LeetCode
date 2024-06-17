#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    void addOne(string& s) {
        int i = N-1;
        while (s[i] == '1') {
            i--;
        }
        s[i] = '1';
        i++;
        while (i < N) {
            s[i] = '0';
            i++;
        }
    }
    int numSteps(string s) {
        s.insert(0, "0");
        N = s.size();
        string target(N, '0');
        target[N-1] = '1';
        int ans = 0;
        while (s != target) {
            if (s[N-1] == '1') {
                addOne(s);
            } else {
                // right shift
                for (int i = N-1; i > 0; i--) {
                    s[i] = s[i-1];
                }
                s[0] = '0';
            }
            ans++;
        }
        return ans;
    }
};


int main() {
  string str = "1101";
  Solution s;
  cout << s.numSteps(str) << endl;
  return 0;
}