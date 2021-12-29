#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        map<int, vector<vector<int>>> storage;

        for(auto it : points)
        {
            storage[it[0]*it[0]+it[1]*it[1]].push_back(it);
        }

        bool out = false;

        for(auto it = storage.begin(); it != storage.end(); it++)
        {
            for(auto iit : it->second)
            {
                res.push_back(iit);
                k--;

                if(0 == k)
                {
                    out = true;
                    break;
                }
            }

            if(out)
                break;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vctPoints1;
    vctPoints1.push_back({1, 3});
    vctPoints1.push_back({-2, 2});

    vector<vector<int>> vctPoints2;
    vctPoints2.push_back({0, 1});
    vctPoints2.push_back({1, 0});

    for(auto it : sol.kClosest(vctPoints1, 1))
    {
        for(auto iit : it)
        {
            cout << iit << " "s;
        }
        cout << endl;
    }

    for(auto it : sol.kClosest(vctPoints2, 2))
    {
        for(auto iit : it)
        {
            cout << iit << " "s;
        }
        cout << endl;
    }
}
