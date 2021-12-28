#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int mask = 0;
        int count = 0;

        // invert all bits
        res = ~num;

        // while num is greater than zero
        while(0 != num)
        {
            // set 1 to mask in count position
            mask |= (1 << count);

            // shift num to right
            num >>= 1;

            // increase counter
            count++;
        }

        // take result by mask
        res &= mask;

        return res;
    }
};

int main()
{
    Solution sol;

    cout << sol.findComplement(170) << endl;
}
