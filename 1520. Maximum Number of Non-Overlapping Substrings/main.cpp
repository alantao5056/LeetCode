#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> maxNumOfSubstrings(string s) {
    int N = s.size();

    vector<int> l(26, -1);
    vector<int> r(26, -1);
    for (int i = 0; i < N; i++) {
      if (l[s[i]-'a'] == -1) l[s[i]-'a'] = i;
    }
    
    for (int i = N-1; i >= 0; i--) {
      if (r[s[i]-'a'] == -1) r[s[i]-'a'] = i;
    }


  }
};

int main() {

  string in; cin >> in;

  Solution s;
  vector<string> ans = s.maxNumOfSubstrings(in);

  for (string temp : ans) {
    cout << temp << endl;
  }

  return 0;
}
