#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        TreeNode *current = root;
        stack<TreeNode*> stackNode;

        while((nullptr != current) || !stackNode.empty())
        {
            while(nullptr != current)
            {
                stackNode.push(current);

                current = current->left;
            }

            current = stackNode.top();

            res.push_back(current->val);

            stackNode.pop();

            current = current->right;
        }

        return res;
    }
};

int main()
{
    TreeNode node3 = {3, nullptr, nullptr};
    TreeNode node2 = {2, &node3, nullptr};
    TreeNode node1 = {1, nullptr, &node2};
    Solution sol;

    for(int val : sol.inorderTraversal(&node1))
    {
        cout << val << " "s;
    }
}
