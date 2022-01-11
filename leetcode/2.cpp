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
        ListNode* curr;
        int order;
        int num1 = 0;
        int num2 = 0;
        
        curr = l1;
        order = 0;
        while(nullptr != curr)
        {
            num1 += curr->val*pow(10,order);
            order++;
            curr = curr->next;
        }

        curr = l2;
        order = 0;
        while(nullptr != curr)
        {
            num2 += curr->val*pow(10,order);
            order++;
            curr = curr->next;
        }

        int num = num1 + num2;

        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        while(num > 0)
        {
            ListNode curr(num%10);

            cout << "val " << curr.val << endl;

            if(nullptr == head)
            {
                head = &curr;
            }
            else
            {
                prev->next = &curr;
            }

            prev = &curr;

            num /= 10;
        }

        cout << num1 << " "s << num2 << endl;

        return head;
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
