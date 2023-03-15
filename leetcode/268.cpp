#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t size = nums.size();

        if (nums[0] != 0) {
            return 0;
        }
        if (size == 1) {
            return 1;
        }

        int ret = 0;
        for (size_t i = 0; i < size; ++i) {
            if (i+1 < size) {
                if (nums[i+1] != nums[i]+1) {
                    ret = nums[i]+1;
                    break;
                }
            }
            else {
                ret = nums[i]+1;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    {
    vector<int> vct{0};
    cout << "missing (1) " << sol.missingNumber(vct) << endl;
    }
    {
    vector<int> vct{1};
    cout << "missing (0) " << sol.missingNumber(vct) << endl;
    }
    {
    vector<int> vct{1,2};
    cout << "missing (0) " << sol.missingNumber(vct) << endl;
    }
    {
    vector<int> vct{3,0,1};
    cout << "missing (2) " << sol.missingNumber(vct) << endl;
    }
    {
    vector<int> vct{0,1};
    cout << "missing (2) " << sol.missingNumber(vct) << endl;
    }
    {
    vector<int> vct{9,6,4,2,3,5,7,0,1};
    cout << "missing (8) " << sol.missingNumber(vct) << endl;
    }
}
