#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int  first;      // индекс первого элемента
        int  second;     // индекс второго элемента

        bool found;      // признак завершения поиска

        vector<int> out; // выходной вектор
        out.clear();

        int  size = nums.size();

        if( ( 2 > size ) || ( size > 10000 ) )
            return out;

        if( ( -1000000000 > target ) || ( target > 1000000000 ) )
            return out;
        
        found = false;

        // цикл по вектору
        for( int i = 0; i < size; i++ )
        {
            // второй цикл по оставшейся части вектора
            // второй цикл начинаем от i, дабы не перебирать повторные суммы
            for( int j = i+1; j < size; j++ )
            {
                if( target == ( nums.at(i) + nums.at(j) ) )
                {
                    out.push_back(i);
                    out.push_back(j);
                    found = true;
                    break;
                }
            }

            if( found )
                break;
        }

        return out;
    }
};

int main()
{
    Solution sol;
    int trg;
    vector<int> vect_in;
    vector<int> vect_out;

    trg = 9;
    vect_in.push_back(2);
    vect_in.push_back(7);
    vect_in.push_back(11);
    vect_in.push_back(15);

    vect_out = sol.twoSum( vect_in, trg );

    for( int it : vect_out )
    {
        cout << it << ", ";
    }

    cout << endl;

    return 0;
}