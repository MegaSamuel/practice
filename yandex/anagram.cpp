#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    for( int i = 0; i < n; ++i ) 
    {
        string first_word, second_word;
        cin >> first_word >> second_word;

        map<char, int> mapFirstWord;
        map<char, int> mapSecondWord;

        for( const char ch : first_word )
        {
            ++mapFirstWord[ch];
        }
        for( const char ch : second_word )
        {
            ++mapSecondWord[ch];
        }

        if( mapFirstWord == mapSecondWord ) 
        {
            cout << "YES"s << endl;
        } else 
        {
            cout << "NO"s << endl;
        }
    }

    return 0;
}
