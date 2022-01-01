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
        int depth1;
        int depth2;
        TreeNode *current1 = p;
        TreeNode *current2 = q;
        stack<TreeNode*> stackNode1;
        stack<TreeNode*> stackNode2;

        if((nullptr == p) && (nullptr == q))
            return true;

        if(nullptr == p)
            return false;

        if(nullptr == q)
            return false;

        while((nullptr != current1) || (nullptr != current2) || !stackNode1.empty() || !stackNode2.empty())
        {
            depth1 = 0;
            while(nullptr != current1)
            {
                depth1++;

                stackNode1.push(current1);

                current1 = current1->left;
            }

            depth2 = 0;
            while(nullptr != current2)
            {
                depth2++;

                stackNode2.push(current2);

                current2 = current2->left;
            }

            if(depth1 != depth2)
            {
                return false;
            }

            current1 = stackNode1.top();
            current2 = stackNode2.top();

            if(current1->val != current2->val)
                return false;

            stackNode1.pop();
            stackNode2.pop();

            current1 = current1->right;
            current2 = current2->right;
        }

        if(!stackNode1.empty() || !stackNode2.empty())
        {
            return false;
        }

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
