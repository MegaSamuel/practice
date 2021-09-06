#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool complete = false;
        string result;

        result.clear();

        // если вектор пустой, то выход
        if(strs.empty())
            return result;

        // повторяем х раз, х - длина первой строки
        for( int i = 0; i < strs.at(0).size(); i++ )
        {
            // символ строки
            char ch = strs.at(0).at(i);

            // проход по вектору
            for( string it : strs )
            {
                // если строка короче чем проверяемая позиция, то завершаем
                if( it.size() < i+1 )
                {
                    complete = true;
                    break;
                }

                // если проверяемый символ не совпадает с символом в строке, то завершаем
                if( ch != it.at(i) )
                {
                    complete = true;
                    break;
                }
            }

            if( complete )
            {
                break;
            }

            // добавляем символ к префиксу
            result.push_back( strs.at(0).at(i) );
        }

        return result;
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
