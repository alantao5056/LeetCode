#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

string optimalDivision(vector<int>& nums)
{
  int N = nums.size();

  vector<vector<double>> dps(N, vector<double>(N));
  vector<vector<double>> dpb(N, vector<double>(N));

  for (int i = 0; i < N; i++)
  {
    dps[i][i] = nums[i];
    dpb[i][i] = nums[i];
    if (i < N - 1)
    {
      dps[i][i + 1] = (double)nums[i] / nums[i + 1];
      dpb[i][i + 1] = (double)nums[i] / nums[i + 1];
    }
  }

  vector<vector<bool>> dbs(N, vector<bool>(N)); // false = no par, true = par on right
  vector<vector<bool>> dbb(N, vector<bool>(N)); // false = no par, true = par on right
  for (int s = 2; s < N; s++)
  {
    for (int i = 0; i < N - s; i++)
    {
      int j = i + s;
      double one = dpb[i][j - 1] / nums[j];
      double two = (double)nums[i] / dps[i + 1][j];
      if (one > two)
      {
        dpb[i][j] = one;
        dbb[i][j] = false;
      }
      else
      {
        dpb[i][j] = two;
        dbb[i][j] = true;
      }

      one = dps[i][j-1] / nums[j];
      two = (double) nums[i] / dpb[i+1][j];
      if (one < two) {
        dps[i][j] = one;
        dbs[i][j] = false;
      } else {
        dps[i][j] = two;
        dbs[i][j] = true;
      }
    }
  }

  vector<int> spar;
  vector<int> epar;
  int i = 0;
  int j = N - 1;
  bool cur = true; // big
  while (j - i > 1)
  {
    if (cur) {
      if (dbb[i][j])
      {
        spar.push_back(i + 1);
        epar.push_back(j);
        i++;
        cur = false;
      }
      else
      {
        j--;
      }
    }
    else {
      if (dbs[i][j]) {
        spar.push_back(i + 1);
        epar.push_back(j);
        i++;
        cur = true;
      }
      else {
        j--;
      }
    }
  }

  string res = "";
  int s = 0;
  int e = 0;
  for (int i = 0; i < N; i++)
  {
    while (s < spar.size() && spar[s] == i)
    {
      res += "(";
      s++;
    }
    res += to_string(nums[i]);
    while (e < epar.size() && epar[e] == i)
    {
      res += ")";
      e++;
    }
    if (i < N - 1)
    {
      res += "/";
    }
  }

  return res;
}

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  cout << optimalDivision(nums) << endl;

  return 0;
}