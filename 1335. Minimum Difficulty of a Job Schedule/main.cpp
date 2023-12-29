#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int N = jobDifficulty.size();

        if (d > N) return -1;

        vector<vector<int>> dp(d+1, vector<int>(N, 1000000000));

        int curMax = 0;
        for (int i = 0; i < N; i++)
        {
            curMax = max(curMax, jobDifficulty[i]);
            dp[1][i] = curMax;
        }

        for (int i = 2; i <= d; i++)
        {
            for (int j = i-1; j < N; j++)
            {
                int curMax = jobDifficulty[j];
                for (int k = j-1; k >= 0; k--)
                {

                    dp[i][j] = min(dp[i][j], dp[i-1][k] + curMax);
                    curMax = max(curMax, jobDifficulty[k]);
                }
            }
        }

        return dp[d][N-1];
    }
};

int main()
{
    vector<int> jobDifficulty = {1, 1, 1};
    int d = 3;

    Solution s;
    cout << s.minDifficulty(jobDifficulty, d) << endl;

    return 0;
}
