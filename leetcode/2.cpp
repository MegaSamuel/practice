#include <iostream>
#include <cmath>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;

        int carry = 0;

        ListNode *current = new ListNode(0);
        ListNode *ret = current;

        while((nullptr != p) || (nullptr != q))
        {
            int sum = 0;
            if(nullptr != p)
            {
                sum += p->val;
                p = p->next;
            }

            if(nullptr != q)
            {
                sum += q->val;
                q = q->next;
            }

            sum += carry;

            carry = sum/10;

            current->next = new ListNode(sum%10);

            current = current->next;
        }

        // last element
        if(carry)
        {
            current->next = new ListNode(carry);
        }

        // first node is zero, take second node
        return ret->next;
    }
};

int main()
{
    ListNode node3(3);
    ListNode node2(4, &node3);
    ListNode node1(2, &node2);

    ListNode node6(4);
    ListNode node5(6, &node6);
    ListNode node4(5, &node5);

    Solution sol;

    ListNode *head;
    head = sol.addTwoNumbers(&node1, &node4);

    while(nullptr != head)
    {
        cout << head->val << " "s;
        head = head->next;
    }
}
