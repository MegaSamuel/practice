#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if( 0 == n )
            return 0;

        if( 1 == n )
            return 1;

        if( 2 == n )
            return 1;

        return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};

int main()
{
    vector<int>  input  = {0,1,2,4,25};
    vector<int>  output = {0,1,1,4,1389537};
    Solution sol;

    for( int i = 0; i < static_cast<int>(input.size()); i++ )
    {
        if( output[i] == sol.tribonacci( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }
}
