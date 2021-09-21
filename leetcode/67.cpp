#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void Reverse( string& str )
    {
        int l, r;
        l = 0;
        r = str.size() - 1;
        while( l < r )
        {
            swap( str[l], str[r] );
            l++;
            r--;
        }
    }

    string addBinary(string a, string b) {
        string out;

        // разворачиваем входные строки
        Reverse( a );
        Reverse( b );

        string A;
        string B;

        // выбираем самую динную строку
        if( a.size() >= b.size() )
        {
            A = a;
            B = b;
        }
        else
        {
            A = b;
            B = a;
        }

        bool over = false;

        for( int i = 0; i < A.size(); i++ )
        {
            char x, y;

            x = A[i];
            if( i < B.size() )
            {
                y = B[i];
            }
            else
            {
                // если строка кончилась
                y = '0';
            }

            if( '0' == x )
            {
                if( '0' == y )
                {
                    if( over )
                    {
                        out.push_back( '1' );
                        over = false;
                    }
                    else
                    {
                        out.push_back( '0' );
                    }
                }
                else if( '1' == y )
                {
                    if( over )
                    {
                        out.push_back( '0' );
                        over = true;
                    }
                    else
                    {
                        out.push_back( '1' );
                    }
                }
            }
            else if( '1' == x )
            {
                if( '0' == y )
                {
                    if( over )
                    {
                        out.push_back( '0' );
                        over = true;
                    }
                    else
                    {
                        out.push_back( '1' );
                    }
                }
                else if( '1' == y )
                {
                    if( over )
                    {
                        out.push_back( '1' );
                        over = true;
                    }
                    else
                    {
                        out.push_back( '0' );
                        over = true;
                    }
                }
            }
        }

        if( over )
        {
            out.push_back( '1' );
        }

        // разворот итоговой строки
        Reverse( out );

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
    vct_in.push_back( pair( "1010", "" ) );

    vct_out.push_back( "100" );
    vct_out.push_back( "10101" );
    vct_out.push_back( "1010" );

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