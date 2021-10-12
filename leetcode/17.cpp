#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void combination(vector<string>& res, const vector<string>& dict, string str, unsigned n) {
        // базовый случай
        if( n == dict.size() )
        {
            if(!str.empty())
            {
                res.push_back(str);
            }
            return;
        }

        // рекурсивный случай
        for( unsigned i = 0; i < dict[n].size(); i++ )
        {
            combination(res, dict, str+dict[n][i], n+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        // слова
        string str2 = "abc";
        string str3 = "def";
        string str4 = "ghi";
        string str5 = "jkl";
        string str6 = "mno";
        string str7 = "pqrs";
        string str8 = "tuv";
        string str9 = "wxyz";

        // словарь
        vector<string> dict;

        // заполняем словарь
        for( unsigned i = 0; i < digits.size(); i++ )
        {
            if( '2' == digits[i] )
                dict.push_back(str2);
            else if( '3' == digits[i] )
                dict.push_back(str3);
            else if( '4' == digits[i] )
                dict.push_back(str4);
            else if( '5' == digits[i] )
                dict.push_back(str5);
            else if( '6' == digits[i] )
                dict.push_back(str6);
            else if( '7' == digits[i] )
                dict.push_back(str7);
            else if( '8' == digits[i] )
                dict.push_back(str8);
            else if( '9' == digits[i] )
                dict.push_back(str9);
        }

        combination(result, dict, "", 0);

        return result;
    }
};

int main()
{
    Solution sol;

    for( const auto& it : sol.letterCombinations("") )
    {
        cout << it << " ";
    }
}
