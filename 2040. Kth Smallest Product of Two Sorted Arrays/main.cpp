#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

ll count(vector<int>& nums1, vector<int>&nums2, vector<int>& rnums2, ll v) {
  // count products <= v
  int N = nums1.size(); int M = nums2.size();

  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    int low = 0;
    int high = M-1;
    if (nums1[i] >= 0) {
      if ((ll)nums2[0] * nums1[i] > v) continue;
      
      while (low < high) { // notice we do not compare element at mid with our target
        int mid = low + (high - low + 1) / 2;
        if ((ll)nums2[mid] * nums1[i] > v)
          high = mid - 1;
        else
          low = mid;
      }
    } else {
      if ((ll)rnums2[0] * nums1[i] > v) continue;
      
      while (low < high) { // notice we do not compare element at mid with our target
        int mid = low + (high - low + 1) / 2;
        if ((ll)rnums2[mid] * nums1[i] > v)
          high = mid - 1;
        else
          low = mid;
      }
    }

    cnt += low + 1;
  }

  return cnt;
}
long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
  ll low = -pow(10, 10);
  ll high = pow(10, 10);
  vector<int> rnums2 = nums2;
  sort(rnums2.begin(), rnums2.end(), greater<>());
  
  while (low < high) { // notice we do not compare element at mid with our target
    ll mid = low + (high - low) / 2;
    ll res = count(nums1, nums2, rnums2, mid);
    if (res >= k)
      high = mid;
    else
      low = mid + 1;
  }

  return low;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int N, M;
  ll K;
  cin >> N >> M >> K;

  vector<int> nums1(N);
  for (int i = 0; i < N; i++) {
    cin >> nums1[i];
  }

  vector<int> nums2(M);
  for (int i = 0; i < M; i++) {
    cin >> nums2[i];
  }

  cout << kthSmallestProduct(nums1, nums2, K) << endl;

  return 0;
}