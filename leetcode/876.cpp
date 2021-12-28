#include <iostream>

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
    ListNode* middleNode(ListNode* head) {
        ListNode *current = head;
        int index;
        int node_count = 0;

        // count nodes
        while(nullptr != current)
        {
            node_count++;
            current = current->next;
        }

        // find index of middle
        index = node_count / 2 + 1;

        //cout << "node count "s << node_count << " ind "s << index << endl;

        current = head;
        node_count = 0;

        // count nodes again
        while(nullptr != current)
        {
            node_count++;
            if(index == node_count)
            {
                // if we are at the middle
                break;
            }
            current = current->next;
        }

        return current;
    }
};

int main()
{
#if 1
    //in  [1,2,3,4,5]
    //out [3,4,5]
    ListNode node5(5, nullptr);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);
#else
    //in  [1,2,3,4,5,6]
    //out [4,5,6]
    ListNode node6(6, nullptr);
    ListNode node5(5, &node6);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);
#endif

    Solution sol;

    ListNode *node = sol.middleNode(&node1);

    ListNode *current = node;

    while(nullptr != current)
    {
        cout << current->val << " "s;
        current = current->next;
    }
}
