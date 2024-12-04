#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n; cin >> n;

  int steps = 0;
  int cur = 1;
  int copy = 0;

  while (cur != n) {
    if (n % cur == 0) {
      copy = cur;
      steps++;
    }

    cur += copy;
    steps++;
  }

  cout << steps << endl;

  return 0;
}