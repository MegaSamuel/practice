#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        int res = 0;
        int pop;

        while( x != 0 )
        {
            pop = x % 10;
            x /= 10;
            // if( res > INT_MAX/10 || ( res == INT_MAX / 10 && pop > 7 ) ) 
            //     return 0;
            // if( res < INT_MIN/10 || ( res == INT_MIN / 10 && pop < -8 ) ) 
            //     return 0;

            // проверки на переполнение
            // если результат больше max/10 или меньше min/10
            // то при добвалении pop произойдет переполнение
            if( res > INT_MAX/10 ) 
                return 0;
            if( res < INT_MIN/10 ) 
                return 0;

            res = res * 10 + pop;
        }

        return res;
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

    cout << endl;
    cout << sol.reverse( -2147483412 ) << endl;
    cout << endl;
    cout << sol.reverse( -2147483648 ) << endl;
    cout << endl;
    cout << sol.reverse( 1534236469 ) << endl;

    return 0;
}