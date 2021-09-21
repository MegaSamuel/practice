#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return x;
    }
};

int main()
{
    Solution sol;
    vector<int> vct_in = {4, 8};
    vector<int> vct_out = {2, 2};

    for( int i = 0; i < vct_in.size(); i++ )
    {
        if( vct_out[i] == sol.mySqrt( vct_in[i] ) )
        {
            cout << i << " - PASS" << endl;
        }
        else
        {
            cout << i << " - FAIL" << endl;
        }
    }
}