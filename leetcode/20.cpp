#include <iostream>
#include <string>
// #include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool result = false;
        int open_p1 = 0, close_p1 = 0;
        int open_p2 = 0, close_p2 = 0;
        int open_p3 = 0, close_p3 = 0;
        // vector<char> vct;

        // vct.push_back('(');
        // vct.push_back(')');
        // vct.push_back('{');
        // vct.push_back('}');
        // vct.push_back('[');
        // vct.push_back(']');

        // solution
        for( int i = 0; i < s.size(); i++ )
        {
            switch( s.at(i) )
            {
                case '(':
                    open_p1 += 1;
                    break;
                case ')':
                    close_p1 += 1;
                    break;
                case '{':
                    open_p2 += 1;
                    break;
                case '}':
                    close_p2 += 1;
                    break;
                case '[':
                    open_p3 += 1;
                    break;
                case ']':
                    close_p3 += 1;
                    break;
                default:
                    break;
            }
        }

        if( ( open_p1 == close_p1 ) && ( open_p2 == close_p2 ) && ( open_p3 == close_p3 ) )
            result = true;

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
