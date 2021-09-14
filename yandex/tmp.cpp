#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination ) 
{
    for( string& str : source )
    {
        destination.push_back( str );
    }
    
    source.clear();
}

int main()
{
    vector<string> source = {"how", "to", "learn"};
    vector<string> destination = {"c++"};
    MoveStrings(source, destination);

    for( auto &it : destination )
    {
        cout << it << " ";
    }

    return 0;
}