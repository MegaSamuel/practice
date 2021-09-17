#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<string> vctStr;
    vector<int> vctLength;

    vctStr.push_back("Hello World");
    vctStr.push_back("   fly me   to   the moon  ");
    vctStr.push_back("luffy is still joyboy");

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