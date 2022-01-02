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
    bool isSymmetric(TreeNode* root) {
        int depth_l;
        int depth_r;
        TreeNode* current_l;
        TreeNode* current_r;
        stack<TreeNode*> stack_l; 
        stack<TreeNode*> stack_r;

        if(nullptr == root)
            return false;

        current_l = root->left;
        current_r = root->right;

        while((nullptr != current_l) || !stack_l.empty() || (nullptr != current_r) || !stack_r.empty())
        {
            depth_l = 0;
            while(nullptr != current_l)
            {
                depth_l++;

                stack_l.push(current_l);

                current_l = const_cast<TreeNode*>(current_l->left);
            }

            depth_r = 0;
            while(nullptr != current_r)
            {
                depth_r++;

                stack_r.push(current_r);

                current_r = const_cast<TreeNode*>(current_r->right);
            }

            if(depth_l != depth_r)
            {
                return false;
            }

            current_l = stack_l.top();
            current_r = stack_r.top();

            if( current_l->val != current_r->val )
            {
                return false;
            }

            stack_l.pop();
            stack_r.pop();

            current_l = const_cast<TreeNode*>(current_l->right);
            current_r = const_cast<TreeNode*>(current_r->left);
        }

        if(!stack_l.empty() || !stack_r.empty())
        {
            return false;
        }

        return true;
    }
};

int main()
{
    TreeNode node7 = {3, nullptr, nullptr};
    TreeNode node6 = {4, nullptr, nullptr};
    TreeNode node5 = {4, nullptr, nullptr};
    TreeNode node4 = {3, nullptr, nullptr};
    TreeNode node3 = {2, &node6, &node7};
    TreeNode node2 = {2, &node4, &node5};
    TreeNode node1 = {1, &node2, &node3};

    Solution sol;

    cout << sol.isSymmetric(&node1);
}
