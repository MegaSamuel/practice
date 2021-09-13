#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind = 0;

        if( haystack.empty() || needle.empty() )
            return 0;
        
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

    return 0;
}