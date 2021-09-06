#include <iostream>
#include <string>

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

        for( int i = 0; i < s.size(); i++ )
        {
            if( '(' == s.at(i) )
            {
                // строка консилась
                if( i+1 == s.size() )
                {
                    result = false;
                    break;
                }

                // после открытой скоби идет закрытая другого типа
                if( ( '}' == s.at(i+1) ) || ( ( ']' == s.at(i+1) ) ) )
                {
                    result = false;
                    break;
                }
            }

            if( '{' == s.at(i) )
            {
                // строка консилась
                if( i+1 == s.size() )
                {
                    result = false;
                    break;
                }

                // после открытой скоби идет закрытая другого типа
                if( ( ')' == s.at(i+1) ) || ( ( ']' == s.at(i+1) ) ) )
                {
                    result = false;
                    break;
                }
            }

            if( '[' == s.at(i) )
            {
                // строка консилась
                if( i+1 == s.size() )
                {
                    result = false;
                    break;
                }

                // после открытой скоби идет закрытая другого типа
                if( ( '}' == s.at(i+1) ) || ( ( ')' == s.at(i+1) ) ) )
                {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    string str1 = "()";
    string str2 = "()[]{}";
    string str3 = "(]";
    string str4 = "([)]";
    string str5 = "{[]}";

    cout << sol.isValid(str1) << endl;
    cout << sol.isValid(str2) << endl;
    cout << sol.isValid(str3) << endl;
    cout << sol.isValid(str4) << endl;
    cout << sol.isValid(str5) << endl;

    return 0;
}
