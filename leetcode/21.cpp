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

    void insertAtTheEnd( ListNode** head, int value )
    {
        ListNode *node = new ListNode( value );

        if( *head == nullptr )
        {
            *head = node;
            return;
        }

        ListNode *last = *head;
        while( last->next != nullptr )
        {
            last = last->next;
        }

        last->next = node;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        ListNode *tmp1;
        ListNode *tmp2;

        // оба списка пустые
        if( ( nullptr == l1 ) && ( nullptr == l2 ) )
        {
            return nullptr;
        }

        // пустой только первый
        if( ( nullptr == l1 ) && ( nullptr != l2 ) )
        {
            return l2;
        }

        // пустой только второй
        if( ( nullptr != l1 ) && ( nullptr == l2 ) )
        {
            return l1;
        }

        // начинаем с голов
        tmp1 = l1;
        tmp2 = l2;

        // проход по первому списку
        while( tmp1 != nullptr )
        {
            // проход по второму списку
            while( tmp2 != nullptr )
            {
                if( tmp1->val >= tmp2->val )
                {
                    // узел результата
                    insertAtTheEnd( &result, tmp2->val );

                    // следующий узел списка 2
                    tmp2 = tmp2->next;
                }
                else
                {
                    break;
                }
            }

            // узел результата
            insertAtTheEnd( &result, tmp1->val );

            // следующий узел списка 1
            tmp1 = tmp1->next;

            if( ( nullptr == tmp1 ) && ( nullptr != tmp2 ) )
            {
                while( tmp2 != nullptr )
                {
                    // узел результата
                    insertAtTheEnd( &result, tmp2->val );

                    // следующий узел списка 2
                    tmp2 = tmp2->next;
                }
            }
        }

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
    list_2 = new ListNode(2);
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