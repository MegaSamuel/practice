#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> vct;
        string word;

        for( int i = 0; i < s.size(); i++ )
        {
            if( ' ' == s[i] )
            {
                if( !word.empty() )
                {
                    vct.push_back( word );
                    word.clear();
                }
            }
            else
            {
                word.push_back( s[i] );
            }
        }

        if( !word.empty() )
        {
            vct.push_back( word );
        }

        // for( string it : vct )
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        // cout << "last size " << vct.back().size() << endl;

        return vct.back().size();
    }
};

int main()
{
    Solution sol;
    vector<string> vctStr;
    vector<int> vctLength;

    vctStr.push_back("Hello World"s);
    vctStr.push_back("   fly me   to   the moon  "s);
    vctStr.push_back("luffy is still joyboy"s);

    vctLength.push_back(5);
    vctLength.push_back(4);
    vctLength.push_back(6);

    for( int i = 0; i < vctStr.size(); i++ )
    {
        int result = sol.lengthOfLastWord(vctStr[i]);
        if( vctLength[i] == result )
            cout << i+1 << " - PASS" << endl;
        else
            cout << i+1 << " - FAIL with res " << result << endl;
    }
    
}