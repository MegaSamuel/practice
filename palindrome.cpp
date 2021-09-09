#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    // нужно понять, будет ли s палиндромом
    string tmp;
    
    tmp = s;
    
    reverse( tmp.begin(), tmp.end() );
   
    cout << ( tmp == s ) << endl;
}

int main() {
    IsPalindrome("ara"s);
    IsPalindrome("deer"s);
    return 0;
}
