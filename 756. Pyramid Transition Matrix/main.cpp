#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

class Solution {
  bool rec(vector<int> cur, vector<int>& base, map<pii, vector<int>>& allowed) {
    if (base.size() == 1) return true;
    if (cur.size() == base.size() - 1) return rec(vector<int>(), cur, allowed);
    pii search = {base[cur.size()], base[cur.size()+1]};
    if (allowed.find(search) != allowed.end()) {
      for (int x : allowed[search]) {
        cur.push_back(x);
        if (rec(cur, base, allowed)) return true;
        cur.pop_back();
      }
    }
    return false;
  }

public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    int N = bottom.size();

    vector<int> base(N);
    for (int i = 0; i < N; i++) {
      base[i] = bottom[i]-'A';
    }

    map<pii, vector<int>> m;
    for (string a : allowed) {
      m[{a[0]-'A', a[1]-'A'}].push_back(a[2]-'A');
    }
    return rec(vector<int>(), base, m);
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string bottom; cin >> bottom;
  int A; cin >> A;

  vector<string> allowed(A);
  for (int i = 0; i < A; i++) {
    cin >> allowed[i];
  }

  Solution s;

  cout << s.pyramidTransition(bottom, allowed) << endl;
  
  return 0;
}
