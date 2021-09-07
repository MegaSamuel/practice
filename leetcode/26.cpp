#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;

        // проход по массиву
        for( i = 0; i < nums.size(); i++ )
        {
            j = i+1;
            // просмотр массива от текущей позиции до конца
            // попутно удаляем элементы которые равны i-му
            while( j < nums.size() )
            {
                if( nums[i] == nums[j] )
                {
                   nums.erase( nums.begin()+j );
                }
                else
                {
                    // инкремент индекса только если не было удаления,
                    // если было удаление, то элементы сместились на одну позицию
                    // и необходимо проверить j-й элемент еще раз
                    j++;
                }
            }
        }

        return nums.size();
    }
};

int main()
{
    vector<int> vct;
    Solution sol;

    vct.push_back(0);
    vct.push_back(0);
    vct.push_back(1);
    vct.push_back(1);
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(2);
    vct.push_back(3);
    vct.push_back(3);
    vct.push_back(4);

    cout << sol.removeDuplicates( vct ) << endl;

    for( int it : vct )
    {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
