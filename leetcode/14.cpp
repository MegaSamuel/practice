#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    }
};

int main()
{
    vector<string>  strs1;
    vector<string>  strs2;
    Solution sol;

    strs1.push_back( "flowers" );
    strs1.push_back( "flow" );
    strs1.push_back( "flight" );

    strs2.push_back( "dog" );
    strs2.push_back( "racecar" );
    strs2.push_back( "car" );

    sol.longestCommonPrefix( strs1 );
    sol.longestCommonPrefix( strs2 );

    return 0;
}