#include <iostream>

using namespace std;

int main()
{
    char ch = '3';
    int count = 0;
    string str;

    for(int i = 1; i <= 1000; i++)
    {
        str = to_string(i);
        for(int i = 0; i < str.size(); i++)
        {
            if(ch == str[i])
            {
                count++;
                break;
            }
        }
    }

    cout << count;
}