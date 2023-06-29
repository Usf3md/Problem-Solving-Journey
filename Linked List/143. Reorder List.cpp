
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
ListNode *reorderList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *slowPrev = head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slowPrev->next = nullptr;

    ListNode *prev = nullptr;
    ListNode *curr = slow;
    ListNode *next = slow->next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *l1 = head;
    ListNode *l2 = prev;
    ListNode *temp1 = nullptr;
    ListNode *temp2 = nullptr;
    ListNode *merge = new ListNode();
    ListNode *ptr = merge;

    while (l1 && l2)
    {
        temp1 = l1->next;
        temp2 = l2->next;
        ptr->next = l1;
        ptr = ptr->next;
        ptr->next = l2;
        ptr = ptr->next;
        l1 = temp1;
        l2 = temp2;
    }

    return merge->next;
}
int main()
{
    ListNode *node = reorderList(new ListNode(1));
    while (node)
    {
        std::cout << node->val << ' ';
        node = node->next;
    }
    return 0;
}