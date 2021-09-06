#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool result = true;

        // пустая строка
        if( 0 == s.size() )
            return false;

        if( ( ')' == s.at(0) ) || ( '}' == s.at(0) ) || ( ']' == s.at(0) ) )
            return false;

        int open_p1 = 0;
        int open_p2 = 0;
        int open_p3 = 0;

        for( int i = 0; i < s.size(); i++ )
        {
            if( '(' == s.at(i) )
            {
                open_p1 += 1;
            }

            if( '{' == s.at(i) )
            {
                open_p2 += 1;
            }

            if( '[' == s.at(i) )
            {
                open_p3 += 1;
            }

            if( ')' == s.at(i) )
            {
                //if( ( open_p1 ) && ( open_p2 || open_p3 ) )
                if( open_p2 || open_p3 )
                {
                    result = false;
                    break;
                }

                open_p1 -= 1;
            }

            if( '}' == s.at(i) )
            {
                //if( ( open_p2 ) && ( open_p1 || open_p3 ) )
                if( open_p1 || open_p3 )
                {
                    result = false;
                    break;
                }

                open_p2 -= 1;
            }

            if( ']' == s.at(i) )
            {
                //if( ( open_p3 ) && ( open_p2 || open_p1 ) )
                if( open_p2 || open_p1 )
                {
                    result = false;
                    break;
                }

                open_p3 -= 1;
            }

            if( ( 0 > open_p1 ) || ( 0 > open_p2 ) || ( 0 > open_p3 )  )
            {
                result = false;
                break;
            }
        }

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

    output.push_back(true);
    output.push_back(true);
    output.push_back(false);
    output.push_back(false);
    output.push_back(true);
    output.push_back(false);
    output.push_back(false);

    for( int i = 0; i < input.size(); i++ )
    {
        if( output[i] == sol.isValid( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}
