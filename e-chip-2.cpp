#include <iostream>
#include <vector>

using namespace std;

// функция с алгоритмом двоичного поиска 
int Search_Binary (int arr[], int left, int right, int key)
{
 int midd = 0;
 while (1)
 {
 midd = (left + right) / 2;
 
 if (key < arr[midd])       // если искомое меньше значения в ячейке
 right = midd - 1;      // смещаем правую границу поиска
 else if (key > arr[midd])  // если искомое больше значения в ячейке
 left = midd + 1;    // смещаем левую границу поиска
 else                       // иначе (значения равны)
 return midd;           // функция возвращает индекс ячейки
 
 if (left > right)          // если границы сомкнулись 
 return -1;
 }
}

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

        cout << "begin " << l << " end " << r << " first " << first << " key " << key << endl;

        while ((l <= r) && (flag != true)) 
        {
            mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
 
            if (vArr.at(mid) == key) flag = true; //проверяем ключ со серединным элементом
            if (vArr.at(mid) > key) r = mid - 1; // проверяем, какую часть нужно отбросить
            else l = mid + 1;
        }

        if( flag )
        {
            cout << "index of " << key << " is " << mid << endl;
            second = key;
            break;
        }
        else 
        {
            cout << "not find" << endl;
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
