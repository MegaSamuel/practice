#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;

        while( i <= x )
        {
            i++;

            if( i*i > x )
            {
                return i-1;
            }

            if( i*i == x )
            {
                return i;
            }
        }

        return i;
    }
};

int main()
{
    Solution sol;
    vector<int> vct_in = {0, 1, 4, 8, 6, 2147483647};
    vector<int> vct_out = {0, 1, 2, 2, 2, 46340 };

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