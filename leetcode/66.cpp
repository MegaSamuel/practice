#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> vct;

        for( const int& it : vct )
        {
            cout << it << " ";
        }
        cout << endl;

        return vct;
    }
};

int main()
{
    Solution sol;
    vector<int> vct_in;
    vector<int> vct_out;

    vector<pair<vector<int>, vector<int>>> data;

    vct_in = {1,2,3};
    vct_out = {1,2,4};
    data.push_back( pair(vct_in, vct_out) );

    vct_in = {4,3,2,1};
    vct_out = {4,3,2,2};
    data.push_back( pair(vct_in, vct_out) );

    vct_in = {0};
    vct_out = {1};
    data.push_back( pair(vct_in, vct_out) );

    vct_in = {9};
    vct_out = {1,0};
    data.push_back( pair(vct_in, vct_out) );

    for( int i = 0; i < data.size(); i++ )
    {
        if( data[i].second == sol.plusOne( data[i].first ) )
        {
            cout << i << " - PASS" << endl;
        }
        else
        {
            cout << i << " - FAIL" << endl;
        }
    }

    return 0;
}