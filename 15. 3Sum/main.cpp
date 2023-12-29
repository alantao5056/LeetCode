#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();

        vector<multiset<int>> vm(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = N-1; j >= i; j--)
            {
                vm[i].insert(nums[j]);
            }
        }

        map<int, set<int>> m;
        vector<vector<int>> result;
        for (int i = 0; i < N; i++)
        {
            for (int j = i+1; j < N-1; j++)
            {
                int target = 0 - nums[i] - nums[j];
                if (vm[j+1].find(target) != vm[j+1].end())
                {
                    vector<int> order = {nums[i], target, nums[j]};
                    sort(order.begin(), order.end());
                    if (m.find(order[0]) != m.end())
                    {
                        if (m[order[0]].find(order[1]) != m[order[0]].end())
                        {
                            // already found
                            continue;
                        }
                    }
                    m[order[0]].insert(order[1]);
                    result.push_back(order);
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for (vector<int> r : result)
    {
        cout << r[0] << " " << r[1] << " " << r[2] << endl;
    }

    return 0;
}
