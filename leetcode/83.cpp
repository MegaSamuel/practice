#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return head;        
    }
};

int main()
{
//    [1,1,2,3,3]

    ListNode node5(3, nullptr);
    ListNode node4(3, &node5);
    ListNode node3(2, &node4);
    ListNode node2(1, &node3);
    ListNode node1(1, &node2);

    Solution sol;

    ListNode *node = sol.deleteDuplicates(&node1);

    ListNode *current = node;

    while(nullptr != current)
    {
        cout << current->val << " "s;
        current = current->next;
    }
}
