#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> vct;
        bool over = false;

        // заполняем вектор в обратном порядке
        for( int i = digits.size()-1; i >= 0; i-- )
        {
            vct.push_back( digits[i] );
        }

        // проход по вектору
        for( int i = 0; i < vct.size(); i++ )
        {
            vct[i] += 1;
            over = false;
            
            if( vct[i] < 10 )
            {
                // все хорошо - выходим
                break;
            }
            else
            {
                // если переполнение
                vct[i] %= 10;
                over = true;
            }
        }

        if( over )
        {
            vct.push_back( 1 );
        }

        // разворачиваем вектор
        int l, r;
        l = 0;
        r = vct.size()-1;
        while( l < r )
        {
            swap( vct[l], vct[r] );
            l++;
            r--;
        }

        // for( const int& it : vct )
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        return vct;
    }
};

int main()
{
    Solution sol;
    vector<int> vct_in;
    vector<int> vct_out;

    vector<pair<vector<int>, vector<int>>> data;

    vct_in = {1,2,3};
    vct_out = {1,2,4};
    data.push_back( pair(vct_in, vct_out) );

    vct_in = {4,3,2,1};
    vct_out = {4,3,2,2};
    data.push_back( pair(vct_in, vct_out) );

    vct_in = {0};
    vct_out = {1};
    data.push_back( pair(vct_in, vct_out) );

    vct_in = {9};
    vct_out = {1,0};
    data.push_back( pair(vct_in, vct_out) );

    for( int i = 0; i < data.size(); i++ )
    {
        if( data[i].second == sol.plusOne( data[i].first ) )
        {
            cout << i << " - PASS" << endl;
        }
        else
        {
            cout << i << " - FAIL" << endl;
        }
    }

    return 0;
}