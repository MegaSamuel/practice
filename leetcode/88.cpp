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

        int i, j, k;

        vector<int> tmp(m);

        for(i = 0; i < m; i++)
        {
            tmp[i] = nums1[i];
        }

        i = 0;
        j = 0;
        k = 0;

        while((i < m) && (j < n))
        {
            if(tmp[i] <= nums2[j])
            {
                nums1[k] = tmp[i];
                k++;
                i++;
            }
            else
            {
                nums1[k] = nums2[j];
                k++;
                j++;
            }
        }

        while(i < m)
        {
            nums1[k] = tmp[i];
            k++;
            i++;
        }

        while(j < n)
        {
            nums1[k] = nums2[j];
            k++;
            j++;
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