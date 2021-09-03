#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        int res = 0;

        for( int i = 0; i < s.size(); i++ )
        {
            switch( s[i] )
            {
                case 'M' :
                    res += 1000;
                    break;
                case 'D' :
                    res += 500;
                    break;
                case 'C' :
                    // если дальше идет D или М, то вычитаем 100, иначе прибавляем 100
                    if( ( 'D' == s[i+1] ) || ( 'M' == s[i+1] ) )
                        res -= 100;
                    else
                        res += 100;
                    break;
                case 'L' :
                    res += 50;
                    break;
                case 'X' :
                    // если дальше идет L или C, то вычитаем 10, иначе прибавляем 10
                    if( ( 'L' == s[i+1] ) || ( 'C' == s[i+1] ) )
                        res -= 10;
                    else
                        res += 10;
                    break;
                case 'V' :
                    res += 5;
                    break;
                case 'I' :
                    // если дальше идет V или X, то вычитаем 1, иначе прибавляем 1
                    if( ( 'V' == s[i+1] ) || ( 'X' == s[i+1] ) )
                        res -= 1;
                    else
                        res += 1;
                    break;
            }
        }

        return res;
    }
};

int main()
{
    vector<int>  result;
    vector<string>  str;
    Solution sol;

    result.push_back(100);
    result.push_back(3);
    result.push_back(4);
    result.push_back(9);
    result.push_back(58);
    result.push_back(1994);

    str.push_back( "C" );
    str.push_back( "III" );
    str.push_back( "IV" );
    str.push_back( "IX" );
    str.push_back( "LVIII" );
    str.push_back( "MCMXCIV" );

    for( int i = 0; i < result.size(); i++ )
    {
        if( result[i] == sol.romanToInt( str[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}