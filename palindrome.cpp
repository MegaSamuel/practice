#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    // нужно понять, будет ли s палиндромом
    bool result = true;
    int l, r;
    
    l = 0;
    r = s.size()-1;

    while( l < r )
    {
        if( s[l] != s[r] )
        {
            result = false;
            break;
        }

        l++;
        r--;
    }

    cout << result << endl;
}

int main() {
    IsPalindrome("ara"s);
    IsPalindrome("deer"s);
    return 0;
}
