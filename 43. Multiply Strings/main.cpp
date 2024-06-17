#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    vector<int> d1(201);
    vector<int> d2(201);

    int temp = 200;
    for (int i = num1.size()-1; i >= 0; i--) {
      d1[temp] = num1[i]-'0';
      temp--;
    }

    temp = 200;
    for (int i = num2.size()-1; i >= 0; i--) {
      d2[temp] = num2[i]-'0';
      temp--;
    }

    vector<int> result(401);

    for (int i = 200; i >= 0; i--) {
      int carry = 0;
      vector<int> cur(401);
      for (int j = 200; j >= 0; j--) {
        int prod = d1[i]*d2[j];
        int newc = prod/10;
        int rem = prod%10;
        if (rem + carry >= 10) {
          newc++;
        }

        rem += carry;
        rem %= 10;
        cur[j+200-(200-i)] = rem;
        carry = newc;
      }

      // add cur to result
      carry = 0;
      for (int j = 400; j >= 0; j--) {
        int s = cur[j] + result[j];
        int newc = s/10;
        int rem = s%10;
        if (rem + carry >= 10) {
          newc++;
        }

        rem += carry;
        rem %= 10;
        result[j] = rem;
        carry = newc;
      }
    }

    bool start = false;
    string fin = "";
    for (int i = 0; i < 401; i++) {
      if (result[i] != 0) {
        start = true;
      }
      if (start) {
        fin += '0' + result[i];
      }
    }

    return fin;
  }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string num1, num2;
  cin >> num1 >> num2;

  Solution s;
  cout << s.multiply(num1, num2) << endl;

  return 0;
}