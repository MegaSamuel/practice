#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if( 0 == n )
            return 0;

        if( 1 == n )
            return 1;
        
        int prev = 0;
        int next = 1;

        for( int i = 0; i < n; i++ )
        {
            int temp = next;
            next = prev + next;
            prev = temp;
        }

        return prev;
    }
};

int main()
{
    vector<int>  input  = {0,1,2,3,4,5};
    vector<int>  output = {0,1,1,2,3,5};
    Solution sol;

    for( int i = 0; i < static_cast<int>(input.size()); i++ )
    {
        if( output[i] == sol.fib( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }
}
