#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());

        for(auto it : ranges)
        {
            if((it[0] <= left) && (left <= it[1]))
            {
                left = it[1]+1;
            }
        }

        return (left > right);
    }
};

int main()
{
    Solution sol;

    {
        vector<vector<int>> vct(3);
        vct[0].push_back(1);
        vct[0].push_back(2);
        vct[1].push_back(3);
        vct[1].push_back(4);
        vct[2].push_back(5);
        vct[2].push_back(6);

        assert(true == sol.isCovered(vct, 2, 5));
    }

    {
        vector<vector<int>> vct(2);
        vct[0].push_back(5);
        vct[0].push_back(10);
        vct[1].push_back(10);
        vct[1].push_back(20);

        assert(false == sol.isCovered(vct, 21, 22));
    }

    {
        vector<vector<int>> vct(3);
        vct[0].push_back(37);
        vct[0].push_back(49);
        vct[1].push_back(5);
        vct[1].push_back(17);
        vct[2].push_back(8);
        vct[2].push_back(32);

        assert(false == sol.isCovered(vct, 29, 49));
    }
}
