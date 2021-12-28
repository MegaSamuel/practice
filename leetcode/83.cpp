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
        ListNode *current = head;

        while(nullptr != current)
        {
            // while next node exists
            while(nullptr != current->next)
            {
                // if current value and next value is the same
                if(current->val == current->next->val)
                {
                    current->next = current->next->next;
                }
                else
                {
                    break;
                }
            }

            // going to the next node
            current = current->next;
        }

        // return the head of a new list
        return head;
    }
};

int main()
{
#if 1
    //[1,1,2,3,3]
    ListNode node5(3, nullptr);
    ListNode node4(3, &node5);
    ListNode node3(2, &node4);
    ListNode node2(1, &node3);
    ListNode node1(1, &node2);
#else
    //[1,1,1,1]
    ListNode node4(1, nullptr);
    ListNode node3(1, &node4);
    ListNode node2(1, &node3);
    ListNode node1(1, &node2);
#endif

    Solution sol;

    ListNode *node = sol.deleteDuplicates(&node1);

    ListNode *current = node;

    while(nullptr != current)
    {
        cout << current->val << " "s;
        current = current->next;
    }
}
