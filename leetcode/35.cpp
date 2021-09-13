#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool found = false;
		int left;
		int right;
        int res = 0;
	    int mid = 0;

        if( 0 == nums.size() )
        {
            return 0;
        }

        // if( target < nums.front() )
        // {
        //     return 0;
        // }

        // if( target > nums.back() )
        // {
        //     return nums.size();
        // }

		// начальные значения индексов
		left = 0;
		right = nums.size() - 1;

		while( left <= right )
		{
			mid = ( left + right ) / 2; // индекс середины

            if( nums[mid] == target )
            {
                res = mid;
                break;
            }

			if( nums[mid] > target )
            {
                right = mid - 1;   // элемент с индексом mid больше цели - переносим правую границу
            }
    		else 
            {
				left = mid + 1;   // элемент с индексом mid меньше цели - переносим левую границу
            }

            res = left;
		}

		return res;
    }
};

int main()
{
	vector<int> nums;
	int target;
	int result;
	Solution sol;

	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	target = 5;

	result = sol.searchInsert( nums, target );
	if( 2 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	nums.clear();
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	target = 2;

	result = sol.searchInsert( nums, target );
	if( 1 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	nums.clear();
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	target = 7;

	result = sol.searchInsert( nums, target );
	if( 4 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	nums.clear();
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	target = 0;

	result = sol.searchInsert( nums, target );
	if( 0 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	nums.clear();
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	target = 1;

	result = sol.searchInsert( nums, target );
	if( 0 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	nums.clear();
	nums.push_back(1);
    nums.push_back(2);
	nums.push_back(3);
    nums.push_back(4);
	nums.push_back(5);
    nums.push_back(10);
	target = 2;

	result = sol.searchInsert( nums, target );
	if( 1 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	nums.clear();
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	target = 3;

	result = sol.searchInsert( nums, target );
	if( 1 == result )
		cout << "pass with result " << result << endl;
	else
		cout << "fail with result " << result << endl;

	return 0;
}