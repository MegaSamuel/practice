#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		return 0;
    }
};

int main()
{
	vector<int> nums;
	int target;
	Solution sol;

	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	target = 2;

	if( 2 == sol.searchInsert( nums, target ) )
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}

	return 0;
}