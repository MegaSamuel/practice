#include <iostream>
#include <vector>

using namespace std;

int  main()
{
    int i, j;
    int n;
    int k;
    int tmp;
    vector<int> vPoint;
    vector<int> vArr;

    // ввод количества фишек
    cin >> n;

    // ввод очков
    // отсортированный массив по возрастанию
    for( i = 0; i < n; i++ )
    {
        cin >> tmp;
        vPoint.push_back(tmp);
    }

    // ввод заданного числа
    cin >> k;

    // берем значение val, тогда второе значение это k-val, 
    // его ищем бинарным поиском

    int first;
    int second;

    bool flag; // признак что нашли
    int l;     // индекс левой границы
    int r;     // индекс правой границы
    int mid;   // индекс середины
    int key;   // значение которое ищем

    for( i = 0; i < n; i++ )
    {
        flag = false;

        first = vPoint.at(i);

        vArr.clear();

        for( j = 0; j < n; j++ )
        {
            if( j != i )
            {
                vArr.push_back( vPoint.at(j) );
            }
        }

        l = 0;
        r = vArr.size()-1;

        key = k - first;

        // cout << "begin " << l << " end " << r << " first " << first << " key " << key << endl;

        while ((l <= r) && (flag != true)) 
        {
            mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
 
            if (vArr.at(mid) == key) flag = true; //проверяем ключ со серединным элементом
            if (vArr.at(mid) > key) r = mid - 1; // проверяем, какую часть нужно отбросить
            else l = mid + 1;
        }

        if( flag )
        {
            // cout << "index of " << key << " is " << mid << endl;
            second = key;
            break;
        }
        else 
        {
            // cout << "not find" << endl;
        }
    }

    // результат
    if( flag )
    {
        cout << first << ' ' << second << endl;
    }
    else
    {
        cout << "None" << endl;
    }

    return 0;
}
