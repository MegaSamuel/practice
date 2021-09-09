#include <iostream>
#include <vector>

using namespace std;

// дан массив из 11 элементов содержащий числа от 1 до 10, одно число повторяется, найти его

int main()
{
    int sum1 = 0;
    int sum2 = 0;
    vector<int> vct;

    vct.push_back(10);
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(3);
    vct.push_back(4);
    vct.push_back(5);
    vct.push_back(6);
    vct.push_back(7);
    vct.push_back(8);
    vct.push_back(9);
    vct.push_back(5);

    for( int i = 0; i < vct.size(); i++ )
    {
        // сумма чисел в векторе
        sum1 += vct[i];

        // сумма чисел от 1 до 10 
        if( i > 0 )
            sum2 += i;
    }

    // искомое число это разница сумм
    cout << sum1 - sum2 << endl;

    // данное решение валидно и для сортированного и не сортированного вектора

    return 0;
}