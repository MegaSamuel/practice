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
    // печатаем значения узлов списка
    void printList( ListNode* n )
    {
        while( n != nullptr )
        {
            cout << n->val << endl;
            n = n->next;
        }
        cout << endl;
    }

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
    ListNode *list_res;
    Solution sol;

    // формируем первый список
    list_1 = new ListNode(1);
    list_1->next = new ListNode(2);
    list_1->next->next = new ListNode(4);

    // формируем второй список
    list_2 = new ListNode(1);
    list_2->next = new ListNode(3);
    list_2->next->next = new ListNode(4);

    // сливаем списки
    list_res = sol.mergeTwoLists( list_1, list_2 );

    // вывод на экран
    sol.printList( list_1 );
    sol.printList( list_2 );
    sol.printList( list_res );

    return 0;
}