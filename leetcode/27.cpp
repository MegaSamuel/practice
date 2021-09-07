#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return 0;
    }
};

int main()
{
    int val;
    vector<int> vct;
    Solution sol;

    val = 2;
    vct.push_back(0);
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(2);
    vct.push_back(3);
    vct.push_back(0);
    vct.push_back(4);
    vct.push_back(2);

    cout << sol.removeElement( vct, val ) << endl;

    for( int it : vct )
    {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
