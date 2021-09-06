#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        size_t pos = 0;

        while( pos != string::npos )
        {
            pos = s.find( "()" );
            if( pos != string::npos )
                s.erase( pos, 2 );

            pos = s.find( "{}" );
            if( pos != string::npos )
                s.erase( pos, 2 );

            pos = s.find( "[]" );
            if( pos != string::npos )
                s.erase( pos, 2 );
        }

        if( 0 != s.size() )
            result = false;

        return result;
    }
};

int main()
{
    Solution sol;

    vector<string> input;
    vector<bool> output;

    input.push_back( "()" );
    input.push_back( "()[]{}" );
    input.push_back( "(]" );
    input.push_back( "([)]" );
    input.push_back( "{[]}" );
    input.push_back( "({{{{}}}))" );
    input.push_back( "[([]])" );
    input.push_back( "(([]){})" );

    output.push_back(true);
    output.push_back(true);
    output.push_back(false);
    output.push_back(false);
    output.push_back(true);
    output.push_back(false);
    output.push_back(false);
    output.push_back(true);

    for( int i = 0; i < input.size(); i++ )
    {
        if( output[i] == sol.isValid( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}
