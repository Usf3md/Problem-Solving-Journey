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
bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main()
{
    std::cout << hasCycle(new ListNode(2, new ListNode(4, new ListNode(3))));
    return 0;
}