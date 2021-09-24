#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int ways = 0;

        return ways;
    }
};

int main()
{
    vector<int>  input = {2,3};
    vector<int>  output = {2,3};
    Solution sol;

    for( int i = 0; i < static_cast<int>(input.size()); i++ )
    {
        if( output[i] == sol.climbStairs( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }
}