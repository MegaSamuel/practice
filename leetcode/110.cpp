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
    bool is_balanced(TreeNode* root, int& depth)
    {
        bool b_left;
        bool b_right;
        int d_left = 0;
        int d_right = 0;

        if(nullptr == root)
            return true;

        b_left = is_balanced(root->left, d_left);

        b_right = is_balanced(root->right, d_right);

        depth = max(d_left, d_right) + 1;

        if(abs(d_left-d_right) > 1)
            return false;
        else
            return (b_left && b_right);
    }

    bool isBalanced(TreeNode* root) 
    {
        int depth = 0;

        return is_balanced(root, depth);
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

    cout << sol.isBalanced(&node1) << endl;

    cout << sol.isBalanced(nullptr) << endl;
}
