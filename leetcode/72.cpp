#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(0 == i)
                {
                    dp[i][j] = j;
                }
                else if(0 == j)
                {
                    dp[i][j] = i;
                }
                else
                {
                    int M = word1[i-1] == word2[j-1] ? 0 : 1;

                    dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]+M);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sol;

    cout << sol.minDistance("aa", "aab");
}
