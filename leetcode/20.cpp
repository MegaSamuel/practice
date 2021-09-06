#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        size_t pos1 = 0;
        size_t pos2 = 0;
        size_t pos3 = 0;

        if( s.size() % 2 )
            return false;

        while( ( pos1 != string::npos ) || ( pos2 != string::npos ) || ( pos3 != string::npos ) )
        {
            pos1 = s.find( "()" );
            if( pos1 != string::npos )
                s.erase( pos1, 2 );

            pos2 = s.find( "{}" );
            if( pos2 != string::npos )
                s.erase( pos2, 2 );

            pos3 = s.find( "[]" );
            if( pos3 != string::npos )
                s.erase( pos3, 2 );
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
