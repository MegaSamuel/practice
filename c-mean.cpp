#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i;
    int t;
    vector<int> vct;
    int width;
    int tmp;

    // ввод количества секунд
    cin >> t;

    // ввод выборки
    for( i = 0; i < t; i++ )
    {
        cin >> tmp;
        vct.push_back(tmp);
    }

    // ввод окна сглаживания
    cin >> width;

    int sum = 0;
    vector<int> vSum;

    // первая сумма
    for( i = 0; i < width; i++ )
    {
        sum += vct.at(i);
    }
    vSum.push_back(sum);

    for( i = width; i < vct.size(); i++ )
    {
        // для определения следующих сумм 
        // из предыдущей суммы вычитаем первый элемент и прибавляем следующий
        sum = vSum.at(i-width) - vct.at(i-width) + vct.at(i);

        vSum.push_back(sum);
    }

    // вывод результата
    for( int x : vSum )
    {
        cout << (float)x/width << ' ';
    }

    return 0;
}
