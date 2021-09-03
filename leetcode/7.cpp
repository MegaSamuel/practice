#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        return 0;
    }
};

int main()
{
    vector<int>  input;
    vector<int>  result;
    Solution sol;

    result.push_back(321);
    result.push_back(-321);
    result.push_back(21);
    result.push_back(0);

    input.push_back(123);
    input.push_back(-123);
    input.push_back(120);
    input.push_back(0);

    for( int i = 0; i < result.size(); i++ )
    {
        if( result[i] == sol.reverse( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}