#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string out;

        return out;
    }
};

int main()
{
    Solution sol;
    vector<pair<string, string>> vct_in;
    vector<string> vct_out;

    vct_in.push_back( pair( "11", "1" ) );
    vct_in.push_back( pair( "1010", "1011" ) );

    vct_out.push_back( "100" );
    vct_out.push_back( "10101" );

    for( int i = 0; i < vct_in.size(); i++ )
    {
        if( vct_out[i] == sol.addBinary( vct_in[i].first, vct_in[i].second  ) )
        {
            cout << i << " - PASS" << endl;
        }
        else
        {
            cout << i << " - FAIL" << endl;
        }
    }
}