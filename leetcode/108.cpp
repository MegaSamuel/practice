#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* makeNode(int left_, int right_, const vector<int>& nums_) {
        int left = left_;
        int right = right_;
        int mid = (right - left)/2;

        TreeNode *current = new TreeNode(nums_[mid]);

        if(left < mid-1)
            current->left = makeNode(left, mid-1, nums_);
        if(mid+1 <= right)
            current->right = makeNode(mid+1, right, nums_);

        return current;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        TreeNode *current = makeNode(left, right, nums);

        return current;
    }
};

int main() {
    Solution sol;
    vector<int> vct = {-10,-3,0,5,9};

    sol.sortedArrayToBST(vct);
}
