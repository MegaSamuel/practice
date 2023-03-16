#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer;
        unordered_map<int, int> map_number_count;
        for (int x : nums) {
            ++map_number_count[x];
        }
        for (auto [x, cnt] : map_number_count) {
            if (cnt == 1) {
                answer.push_back(x);
            }
        }
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1,2,1,3,2,5};

    cout << "res ";
    for (int x : sol.singleNumber(nums)) {
        cout << x << " ";
    }
    cout << endl;
}
