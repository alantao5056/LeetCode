#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int N;

class Solution {
  public:
    int waysToMakeFair(vector<int>& nums) {
      int n = nums.size();

      vector<int> prefix(n+1);
      vector<int> half(n+1);
      for (int i = n-1; i >= 0; i--) {
        prefix[i] = prefix[i+1] + nums[i];
        half[i] = half[i+1] + ((i%2)==0 ? nums[i] : 0);
      }

      int one = 0;
      int two = 0;
      int result = 0;
      for (int i = 0; i < n; i++) {
        int one2 = half[i+1];
        int two2 = prefix[i+1]-one2;
        if (one + two2 == two + one2) {
          result++;
        }
        if (i%2==0) {
          one += nums[i];
        } else {
          two += nums[i];
        }
      }

      return result;
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
  cout << s.waysToMakeFair(nums) << endl;

  return 0;
}