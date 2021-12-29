#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return 0;
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
