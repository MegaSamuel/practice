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

    // ввод количества фишек
    cin >> n;

    // ввод очков
    for( i = 0; i < n; i++ )
    {
        cin >> tmp;
        vPoint.push_back(tmp);
    }

    // ввод заданного числа
    cin >> k;

    int first;
    int second;

    bool found = false;

    // цикл по массиву
    for( i = 0; i < n; i++ )
    {
        first = vPoint.at(i);

        // cout << "first " << first << ' ';

        // второй цикл по массиву
        for( j = i+1; j < n; j++ )
        {
            second = vPoint.at(j);

            // cout << "second " << second << ' ';

            if( k == ( first + second ) )
            {
                found = true;
                // cout << "found " << i << j << ' ';
                break;
            }
        }

        // cout << endl;

        if( found )
            break;
    }

    // результат
    if( found )
    {
        cout << first << ' ' << second << endl;
    }
    else
    {
        cout << "None";
    }

    return 0;
}
