#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i;
	int n;
    int tmp;

    // ввод размера массивов
	cin >> n;

    // массивы
    vector<int> vct1;
    vector<int> vct2;
    vector<int> vct3;

    // ввод первого массива
    for( i = 0; i < n; i++ )
    {
        cin >> tmp;
        vct1.push_back(tmp);
    }

    // ввод второго массива
    for( i = 0; i < n; i++ )
    {
        cin >> tmp;
        vct2.push_back(tmp);
    }

    // формируем итоговый массив
    for( i = 0; i < n; i++ )
    {
        vct3.push_back(vct1.at(i));
        vct3.push_back(vct2.at(i));
    }

    for( int x : vct3 )
	    cout << x << ' ';

    return 0;
}