
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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head || !head->next)
        return nullptr;

    ListNode *fast = head, *slow = head, *prev = head;
    for (int i = 0; i < n - 1; i++)
        fast = fast->next;

    while (fast->next)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }

    if (slow == head)
        return head->next;
    prev->next = slow->next;
    slow->next = nullptr;
    delete slow;
    return head;
}

int main()
{
    ListNode *node = removeNthFromEnd(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))), 2);
    while (node)
    {
        std::cout << node->val << ' ';
        node = node->next;
    }
    return 0;
}