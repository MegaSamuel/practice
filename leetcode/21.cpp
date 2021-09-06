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
    ListNode list_1;
    ListNode list_2;
    ListNode list_res;
    Solution sol;

    list_1 = ListNode();
    list_2 = ListNode();
    list_res = ListNode();

    list_res = *(sol.mergeTwoLists( &list_1, &list_2 ));

    return 0;
}