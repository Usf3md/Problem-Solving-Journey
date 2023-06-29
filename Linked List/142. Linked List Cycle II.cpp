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
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    do
    {
        if (!fast || !fast->next)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    ListNode *slow2 = head;
    while (slow != slow2)
    {
        slow = slow->next;
        slow2 = slow2->next;
    }
    return slow;
}
int main()
{
    ListNode *list = new ListNode(1);
    ListNode *ptr = list;
    ptr->next = new ListNode(2);
    ptr = ptr->next;
    ptr->next = new ListNode(3);
    ptr = ptr->next;
    ptr->next = new ListNode(4);
    ptr = ptr->next;
    ptr->next = new ListNode(5);
    ptr = ptr->next;
    ptr->next = list->next->next;
    ListNode *node = detectCycle(list);
    while (node)
    {
        std::cout << node->val << ' ';
        node = node->next;
        break;
    }
    return 0;
}