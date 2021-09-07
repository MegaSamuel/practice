#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        // проход по вектору
        while( i < nums.size() )
        {
            if( val == nums[i] )
            {
                // удаляем элемент, оставшиеся элементы смещаются на одну позицию
                nums.erase( nums.begin()+i );
            }
            else
            {
                // если не было удаления, то следующий индекс
                i++;
            }
        }

        for( i = 0; i < nums.size(); i++ )
        {

        }

        return nums.size();
    }
};

int main()
{
    int val;
    vector<int> vct;
    Solution sol;

    val = 2;
    vct.push_back(0);
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(2);
    vct.push_back(3);
    vct.push_back(0);
    vct.push_back(4);
    vct.push_back(2);

    cout << sol.removeElement( vct, val ) << endl;

    for( int it : vct )
    {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
