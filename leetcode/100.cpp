#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition for a binary tree node.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return true;
    }
};

int main()
{
    TreeNode node3 = {3, nullptr, nullptr};
    TreeNode node2 = {2, nullptr, nullptr};
    TreeNode node1 = {1, &node2, &node3};

    TreeNode node6 = {3, nullptr, nullptr};
    TreeNode node5 = {2, nullptr, nullptr};
    TreeNode node4 = {1, &node5, &node6};

    Solution sol;

    cout << sol.isSameTree(&node1, &node4);
}
