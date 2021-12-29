#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int cur_sum = 0;
 
        for(int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            cur_sum = cur_sum + nums[i];

            if(max_sum < cur_sum)
                max_sum = cur_sum;
 
            if(cur_sum < 0)
                cur_sum = 0;
        }

        return max_sum;
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;

    if(6 == sol.maxSubArray(nums))
    {
        cout << "PASS"s;
    }
}
