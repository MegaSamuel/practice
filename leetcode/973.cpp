#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;


        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vctPoints;

    vctPoints.push_back({1, 3});
    vctPoints.push_back({-2, 2});

    for(auto it : sol.kClosest(vctPoints, 1))
    {
        for(auto iit : it)
        {
            cout << iit << " "s;
        }
        cout << endl;
    }
}
