#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int q;
    int size = 0;
    int worry_count = 0;
    string str;
    string operation_code;
	vector<string> operation;
    vector<int> queue;

	cin >> q;

    for( int i = 0; i <= q; ++i ) 
    {
        //cin >> operation_code;
        getline( cin, operation_code );

        if( operation_code == "WORRY_COUNT"s )
        {
            for( int k = 0; k < queue.size(); k++ )
            {
                if( -1 == queue[k] )
                {
                    worry_count += 1;
                }
            }
            cout << worry_count << endl;
            worry_count = 0;
        }
        else
        {
            operation.clear();
            str.clear();
            for( int j = 0; j < operation_code.size(); j++ )
            {
                if( ' ' != operation_code[j] )
                {
                    str.push_back(operation_code[j]);
                }
                else
                {
                    operation.push_back(str);
                    //cout << str << endl;
                    str.clear();
                }
            }
            if( !str.empty() )
            {
                operation.push_back(str);
                //cout << str << endl;
            }

            if( 0 == operation.size() )
                continue;

            if( operation[0] == "WORRY"s )
            {
                queue[stoi(operation[1])] = -1;
            }
            else if( operation[0] == "QUIET"s )
            {
                queue[stoi(operation[1])] = 0;
            }
            else if( operation[0] == "COME"s )
            {
                size += stoi(operation[1]);
                queue.resize( size );
            }
        }
    }
}
