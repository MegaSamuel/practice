#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLength = 0;
        // матрица расстояний, размерность +1 по каждому вектору
        vector<vector<char>> vct(nums1.size()+1, vector<char>(nums2.size()+1));

        // проходим с концов векторов и заполняем матрицу
        for(int i = nums1.size()-1; i >= 0; i--)
        {
            for(int j = nums2.size()-1; j >=0 ; j--)
            {
                if( nums1[i] == nums2[j] )
                {
                    vct[i][j] = 1 + vct[i+1][j+1];
                }

                // находим максимум
                maxLength = max(maxLength, static_cast<int>(vct[i][j]));
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};

    cout << sol.findLength(nums1, nums2);
}
