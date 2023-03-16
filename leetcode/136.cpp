#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SolutionSilly {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        size_t size = nums.size();
        for (size_t i = 0; i < size; ++i) {
            if (i+1 < size) {
                if (nums[i] != nums[i+1]) {
                    ret = nums[i];
                    break;
                }
                else {
                    ++i;
                }
            }
            else {
                ret = nums[i];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int x: nums) {
            res ^= x;
        }
        return res;
    }
};

int main()
{
    SolutionSilly ssol;
    Solution sol;
    vector<int> vct{2,2,3,3,8,8,4,5,5,6,6,4,100};
    //vector<int> vct{-1};

    cout << "silly res " << ssol.singleNumber(vct) << endl;
    cout << "smart res " << sol.singleNumber(vct) << endl;
}
