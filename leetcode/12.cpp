#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) 
    {
        string res;
        vector<string> str_digits;
        int digit;

        int count = 0;

        while( num > 0 )
        {
            digit = num%10;
            num /= 10;

            switch( digit )
            {
                case 1:
                    if( 0 == count )
                        str_digits.push_back( "I" );
                    else if( 1 == count )
                        str_digits.push_back( "X" );
                    else if( 2 == count )
                        str_digits.push_back( "C" );
                    else if( 3 == count )
                        str_digits.push_back( "M" );
                    break;
                case 2:
                    if( 0 == count )
                        str_digits.push_back( "II" );
                    else if( 1 == count )
                        str_digits.push_back( "XX" );
                    else if( 2 == count )
                        str_digits.push_back( "CC" );
                    else if( 3 == count )
                        str_digits.push_back( "MM" );
                    break;
                case 3:
                    if( 0 == count )
                        str_digits.push_back( "III" );
                    else if( 1 == count )
                        str_digits.push_back( "XXX" );
                    else if( 2 == count )
                        str_digits.push_back( "CCC" );
                    else if( 3 == count )
                        str_digits.push_back( "MMM" );
                    break;
                case 4:
                    if( 0 == count )
                        str_digits.push_back( "IV" );
                    else if( 1 == count )
                        str_digits.push_back( "XL" );
                    else if( 2 == count )
                        str_digits.push_back( "CD" );
                    break;
                case 5:
                    if( 0 == count )
                        str_digits.push_back( "V" );
                    else if( 1 == count )
                        str_digits.push_back( "L" );
                    else if( 2 == count )
                        str_digits.push_back( "D" );
                    break;
                case 6:
                    if( 0 == count )
                        str_digits.push_back( "VI" );
                    else if( 1 == count )
                        str_digits.push_back( "LX" );
                    else if( 2 == count )
                        str_digits.push_back( "DC" );
                    break;
                case 7:
                    if( 0 == count )
                        str_digits.push_back( "VII" );
                    else if( 1 == count )
                        str_digits.push_back( "LXX" );
                    else if( 2 == count )
                        str_digits.push_back( "DCC" );
                    break;
                case 8:
                    if( 0 == count )
                        str_digits.push_back( "VIII" );
                    else if( 1 == count )
                        str_digits.push_back( "LXXX" );
                    else if( 2 == count )
                        str_digits.push_back( "DCCC" );
                    break;
                case 9:
                    if( 0 == count )
                        str_digits.push_back( "IX" );
                    else if( 1 == count )
                        str_digits.push_back( "XC" );
                    else if( 2 == count )
                        str_digits.push_back( "CM" );
                    break;
            }

            count++;
        }

        for( int i = str_digits.size(); i > 0; i-- )
        {
            res += str_digits[i-1];
        }

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
        if( 0 == output[i].compare( sol.intToRoman( input[i] ) ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }

    return 0;
}