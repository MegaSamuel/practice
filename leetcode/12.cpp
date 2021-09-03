#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) 
    {
        string res;

        return res;
    }
};

int main()
{
    vector<int>  input;
    vector<string>  output;
    Solution sol;

    input.push_back(100);
    input.push_back(3);
    input.push_back(4);
    input.push_back(9);
    input.push_back(58);
    input.push_back(1994);

    output.push_back( "C" );
    output.push_back( "III" );
    output.push_back( "IV" );
    output.push_back( "IX" );
    output.push_back( "LVIII" );
    output.push_back( "MCMXCIV" );

    for( int i = 0; i < input.size(); i++ )
    {
        if( 0 == strcmp( output[i], sol.intToRoman( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}