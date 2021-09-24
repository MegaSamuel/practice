#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
#if 0
    int tribonacci(int n) {
        if( 0 == n )
            return 0;

        if( 1 == n )
            return 1;

        if( 2 == n )
            return 1;

        return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
#else
    int tribonacci(int n) {
        if( 0 == n )
            return 0;

        if( 1 == n )
            return 1;

        if( 2 == n )
            return 1;

        unsigned val3 = 0;
        unsigned val2 = 1;
        unsigned val1 = 1;

        for( int i = 0; i < n; i++ )
        {
            unsigned val1_prev = val1;
            unsigned val2_prev = val2;
            val1 = val3 + val2 + val1;
            val2 = val1_prev;
            val3 = val2_prev;
        }

        return val3;
    }
#endif
};

int main()
{
    vector<int>  input  = {0,1,2,4,25,37};
    vector<int>  output = {0,1,1,4,1389537,2082876103};
    Solution sol;

    for( int i = 0; i < static_cast<int>(input.size()); i++ )
    {
        if( output[i] == sol.tribonacci( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }
}
