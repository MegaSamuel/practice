#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    unsigned long long fibonacci(int number)
    {
        if (number == 0)
            return 0; // базовый случай (условие завершения)
        if (number == 1)
            return 1; // базовый случай (условие завершения)
        return fibonacci(number-1) + fibonacci(number-2);
    }

    unsigned long long fibonacci_fast(int number, int p = 0, int c = 1)
    {
	    return number == 0 ? p : fibonacci_fast(number - 1, c, c + p);
    }

    int climbStairs(int n) {
        int ways = 0;

        //ways = fibonacci(n+1);
        ways = fibonacci_fast(n+1);

        return ways;
    }
};

int main()
{
    vector<int>  input = {2,3,4,5};
    vector<int>  output = {2,3,5,8};
    Solution sol;

    for( int i = 0; i < static_cast<int>(input.size()); i++ )
    {
        if( output[i] == sol.climbStairs( input[i] ) )
            cout << i+1 << " - OK" << endl;
        else
            cout << i+1 << " - FAIL" << endl;
    }
}