#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void printVct( vector<int>& vct )
    {
        for( int it : vct )
        {
            cout << it << endl;
        }

        cout << endl;
    }

    void mergeTwoVct(vector<int>& vct1, vector<int>& vct2) {
        vector<int> result;

        if( vct1.empty() && vct2.empty() )
        {
            return;
        }

        if( !vct1.empty() && vct2.empty() )
        {
            printVct( vct1 );
            return;
        }

        if( vct1.empty() && !vct2.empty() )
        {
            printVct( vct2 );
            return;
        }

        int i, j, k = 0;

        for( i = 0; i < vct1.size(); i++ )
        {
            for( j = k; j < vct2.size(); j++ )
            {
                if( vct1[i] >= vct2[j] )
                {
                    result.push_back(vct2[j]);
                    k++;
                }
                else
                {
                    break;
                }
            }

            result.push_back(vct1[i]);
        }

        printVct( result );
    }
};

int main()
{
    //l1 = [1,2,4], l2 = [1,3,4]
    vector<int> vct_1;
    vector<int> vct_2;
    vector<int> vct_res;
    Solution sol;

    vct_1.push_back(1);
    vct_1.push_back(2);
    vct_1.push_back(4);

    vct_2.push_back(1);
    vct_2.push_back(3);
    vct_2.push_back(4);

    // вывод на экран
    // sol.printVct( vct_1 );
    // sol.printVct( vct_2 );

    sol.mergeTwoVct( vct_1, vct_2 );

    return 0;
}