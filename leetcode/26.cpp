#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return 0;
    }
};

int main()
{
    vector<int> vct;
    Solution sol;

    vct.push_back(1);
    vct.push_back(1);
    vct.push_back(2);

    cout << sol.removeDuplicates( vct ) << endl;

    for( int it : vct )
    {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
