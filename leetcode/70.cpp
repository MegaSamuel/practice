#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int number) {
        int ways=0,n1=1,n2=2;
    
        if(number==n1)
            return 1;
        if(number==n2)
            return 2;

        for(int i=2; i < number; i++){
            ways=n1+n2;
            n1=n2;
            n2=ways;
        }
    
        return ways;
    }
};

int main()
{
    vector<int>  input = {2,3,4,5};
    vector<int>  output = {2,3,5,8};
    Solution sol;

    for( int i = 0; i < static_cast<int>(input.size()); i++ )
    {
        if( output[i] == sol.climbStairs( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }
}