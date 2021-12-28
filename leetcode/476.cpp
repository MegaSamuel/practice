#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res = 0;

        while(0 != num)
        {
            cout << num << " "s << !(num & 0x1) << endl;

            res = (res << 1) + !(num & 0x1);
            num = num >> 1;
        }

        return res;
    }
};

int main()
{
    Solution sol;

    cout << sol.findComplement(170) << endl;
}
