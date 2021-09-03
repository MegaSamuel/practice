#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        int tmp = 0;

        for( int i = 0; i < s.size(); i++ )
        {
            switch( s[i] )
            {
                case 'M' :
                    tmp += 1000;
                    break;
                case 'D' :
                    tmp += 500;
                    break;
                case 'C' :
                    tmp += 100;
                    break;
                case 'L' :
                    tmp += 50;
                    break;
                case 'X' :
                    tmp += 10;
                    break;
                case 'V' :
                    tmp += 5;
                    break;
                case 'I' :
                    tmp += 1;
                    break;
            }
        }

        return tmp;
    }
};

int main()
{
    vector<int>  result;
    vector<string>  str;
    Solution sol;

    result.push_back(3);
    result.push_back(4);
    result.push_back(9);
    result.push_back(58);
    result.push_back(1994);

    str.push_back( "III" );
    str.push_back( "IV" );
    str.push_back( "IX" );
    str.push_back( "LVIII" );
    str.push_back( "MCMXCIV" );

    for( int i = 0; i < 5; i++ )
    {
        if( result[i] == sol.romanToInt( str[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}