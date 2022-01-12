#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum;
        int m;
        int n = static_cast<int>(nums.size());

        sum = accumulate(nums.begin(), nums.end(), 0);
 
        if(0 != sum%2)
            return false;
 
        m = sum/2;

        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
 
        for(int i = 0; i <= n; i++)
            dp[0][i] = true;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i][j-1];

                if(i >= nums[j-1])
                {
                    dp[i][j] = dp[i][j] || dp[i - nums[j-1]][j-1];
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sol;

    vector<int> vct;

    vct.push_back(1);
    vct.push_back(5);
    vct.push_back(11);
    vct.push_back(5);

    cout << sol.canPartition(vct);
}
