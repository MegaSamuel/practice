#include <iostream>

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
    void calcDepth(TreeNode* root, int& depth) 
    {
        int d_left = 0;
        int d_right = 0;

        if(nullptr != root->left)
            calcDepth(root->left, d_left);

        if(nullptr != root->right)
            calcDepth(root->right, d_right);

        depth = max(d_left, d_right) + 1;
    }

    int maxDepth(TreeNode* root) 
    {
        if(nullptr == root)
            return 0;

        int depth = 0;

        calcDepth(root, depth);

        return depth;
    }
};

int main()
{
    Solution sol;

    TreeNode node5 = TreeNode(7);
    TreeNode node4 = TreeNode(15);
    TreeNode node3 = TreeNode(20, &node4, &node5);
    TreeNode node2 = TreeNode(9);
    TreeNode node1 = TreeNode(3, &node2, &node3);

    cout << sol.maxDepth(&node1);
}
