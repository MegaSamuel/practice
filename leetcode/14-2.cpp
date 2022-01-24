#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // если массив строк пуст, то префикс пустой
        if(0 == strs.size())
            return 0;

        // если в массиве всего одна строка, то она и есть префикс
        if(1 == strs.size())
            return strs[0];

        // если больше одной строки в массиве
        
        // сортируем массив строк
        sort(strs.begin(), strs.end());

        // ищем общий префикс для первой и последней строки в массиве

        // меньшая длина из первой и последней строки в массиве
        int shortest = min(strs.front().length(), strs.back().length());

        // определяем максимальную длину общего префикса
        int i = 0;
        while((i < shortest) && (strs.front()[i] == strs.back()[i]))
        {
            i++;
        }

        // возвращаем длину i
        return strs[0].substr(0, i);
    }
};

int main()
{
    vector<string>  strs1;
    vector<string>  strs2;
    Solution sol;

    strs1.push_back( "flowers" );
    strs1.push_back( "flow" );
    strs1.push_back( "flight" );

    strs2.push_back( "dog" );
    strs2.push_back( "racecar" );
    strs2.push_back( "car" );

    cout << sol.longestCommonPrefix( strs1 ) << endl << endl;
    cout << sol.longestCommonPrefix( strs2 ) << endl << endl;

    return 0;
}
