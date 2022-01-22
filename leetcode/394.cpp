#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string out;
        stack<char> stChar;

        for(int i = 0; i < static_cast<int>(s.length()); i++) 
        {
            if(s[i] == ']')
            {
                string str1;
                while(!stChar.empty() && stChar.top() != '[')
                {
                    str1 = stChar.top() + str1;
                    stChar.pop();
                }

                stChar.pop();

                string num;
                while(!stChar.empty() && isdigit(stChar.top()))
                {
                    num = stChar.top() + num;
                    stChar.pop();
                }

                int number = stoi(num);

                string str2;
                for(int j = 0; j < number; j++)
                {
                    str2 += str1;
                }

                for(char it : str2)
                {
                    stChar.push(it);
                }
            }
            else
            {
                stChar.push(s[i]);
            }
        }

        while(!stChar.empty())
        {
            out = stChar.top() + out;
            stChar.pop();
        }

        return out;
    }
};

int main()
{
    Solution sol;

    cout << sol.decodeString("30[a]2[bc]");
}
