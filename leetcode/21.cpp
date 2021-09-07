#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result;

        result = new ListNode();

        return result;
    }
};

int main()
{
    //l1 = [1,2,4], l2 = [1,3,4]
    ListNode *list_1;
    ListNode *list_2;
    ListNode list_res;
    Solution sol;

    list_1 = new ListNode(1);
    list_1->next = new ListNode(2);
    list_1->next->next = new ListNode(4);

    list_2 = new ListNode(1);
    list_2->next = new ListNode(3);
    list_2->next->next = new ListNode(4);

    list_res = *(sol.mergeTwoLists( list_1, list_2 ));

    ListNode *tmp;

    tmp = list_1;

    do
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }while( tmp->next != nullptr );

    return 0;
}