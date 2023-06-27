
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *merge = new ListNode();
    ListNode *ptr = merge;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            ptr->next = list1;
            ptr = ptr->next;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            ptr = ptr->next;
            list2 = list2->next;
        }
    }
    ptr->next = ((list1) ? list1 : list2);
    return merge->next;
}

int main()
{
    ListNode *node = mergeTwoLists(new ListNode(1, new ListNode(2, new ListNode(4))), new ListNode(1, new ListNode(3, new ListNode(4))));
    while (node)
    {
        std::cout << node->val << ' ';
        node = node->next;
    }
    return 0;
}