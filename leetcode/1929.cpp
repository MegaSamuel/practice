#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        vector<int> ans(2*n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> vct;
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(3);

    for(int it : sol.getConcatenation(vct))
    {
        cout << it << " "s;
    }
}
