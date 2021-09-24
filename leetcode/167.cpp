#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>  out;

        // for( int i = 0; i < numbers.size()/2; i++ )
        // {
        //     if( target < numbers[i] + numbers[numbers.size()-1-i] )
        //     {

        //     }
        // }

        return out;        
    }
};

int main()
{
    Solution sol;
    int target = 9;
    vector<int> numbers = {2,7,11,15};

    for( auto it : sol.twoSum( numbers, target ) )
    {
        cout << it << " ";
    }
}