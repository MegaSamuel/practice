#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>  out;

        int l = 0;
        int r = numbers.size()-1;

        while( l < r )
        {
            if( target < numbers[l] + numbers[r] )
            {
                r--;
            }
            else if( target > numbers[l] + numbers[r] )
            {
                l++;
            }
            else
            {
                break;
            }
        }

        out.push_back(++l);
        out.push_back(++r);

        return out;        
    }
};

int main()
{
    Solution sol;
    int target = -1;
    vector<int> numbers = {-1,0};

    for( auto it : sol.twoSum( numbers, target ) )
    {
        cout << it << " ";
    }
}