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

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i, j, k = 0;

        for( i = 0; i < m+n; i++ )
        {
            cout << "i " << i << endl;
            for( j = k; j < n; j++ )
            {
                cout << " j " << j << endl;
                if( nums1[i] > nums2[j] )
                {
                    for( int l=m+n-1; l > i; l-- )
                    {
                        cout << "  l " << l << endl;
                        nums1[l] = nums1[l-1];
                    }
                    nums1[i] = nums2[j];
                    k++;
                }
                else
                {
                    break;
                }
            }
        }
    }
};

int main()
{
    vector<int> vct_1;
    vector<int> vct_2;
    vector<int> vct_res;
    Solution sol;

    vct_1.push_back(1);
    vct_1.push_back(2);
    vct_1.push_back(3);
    vct_1.push_back(0);
    vct_1.push_back(0);
    vct_1.push_back(0);

    vct_2.push_back(2);
    vct_2.push_back(5);
    vct_2.push_back(6);

    // вывод на экран
    // sol.printVct( vct_1 );
    // sol.printVct( vct_2 );

    sol.merge( vct_1, 3, vct_2, 3 );

    sol.printVct( vct_1 );

    return 0;
}