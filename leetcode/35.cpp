#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		unsigned left;
		unsigned right;
		unsigned mid;

		// начальные значения индексов
		left = 0;
		right = nums.size() - 1;
		mid = ( left + right ) / 2;

		while( left <= right )
		{
			mid = ( left + right ) / 2; // индекс середины

    		// if( nums[mid] == target ) // элемент с индексом mid равен ключу
			//   break;
    		
			// if( nums[mid] > target ) 
			// 	right = mid - 1;  // элемент с индексом mid больше ключа - переносим правую границу
    		// else 
			// 	left = mid + 1;   // элемент с индексом mid меньше ключа - переносим левую границу

			if( nums[mid] >= target ) 
				break;
    		else 
				left = mid + 1;   // элемент с индексом mid меньше ключа - переносим левую границу
		}

		return mid;
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

	return 0;
}