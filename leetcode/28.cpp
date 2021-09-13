#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int  i, j;
        bool found = false;
        int  ind = -1;

        // если подстрока пуста - выход, возврат 0
        if( needle.empty() )
            return 0;
        
        // если сторока короче подстроки - выход, возврат -1
        if( haystack.size() < needle.size() )
            return -1;
        
        // проход по строке от начала до момента чтоб умещалась подстрока
        for( i = 0; i <= haystack.size()-needle.size(); i++ )
        {
            // проход по подстроке
            for( j = 0; j < needle.size(); j++ )
            {
                // нашли несовпадение - переходим к следующему i
                if( haystack[i+j] != needle[j] )
                {
                    break;
                }

                // подстрока кончилась - успех
                if( j == (needle.size() - 1) )
                {
                    found = true;
                    ind = i;
                }
            }

            // если нашли - выход
            if( found )
                break;
        }
        
        return ind;
    }
};

int main()
{
    string haystack;
    string needle;
    int result;
    Solution sol;

    haystack = "hello";
    needle = "ll";
    result = sol.strStr( haystack, needle );
    if( 2 == result )
        cout << "pass with result " << result << endl;
    else
        cout << "fail with result " << result << endl;

    haystack = "aaaaa";
    needle = "bba";
    result = sol.strStr( haystack, needle );
    if( -1 == result )
        cout << "pass with result " << result << endl;
    else
        cout << "fail with result " << result << endl;

    haystack = "";
    needle = "";
    result = sol.strStr( haystack, needle );
    if( 0 == result )
        cout << "pass with result " << result << endl;
    else
        cout << "fail with result " << result << endl;

    haystack = "";
    needle = "a";
    result = sol.strStr( haystack, needle );
    if( -1 == result )
        cout << "pass with result " << result << endl;
    else
        cout << "fail with result " << result << endl;

    return 0;
}