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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *sum = new ListNode();
    ListNode *ptr = sum;
    int carry = 0, val1, val2;
    while (l1 || l2 || carry)
    {
        val1 = ((l1) ? l1->val : 0);
        val2 = ((l2) ? l2->val : 0);
        ptr->next = new ListNode((val1 + val2 + carry) % 10);
        ptr = ptr->next;
        carry = (val1 + val2 + carry) / 10;
        l1 = ((l1) ? l1->next : nullptr);
        l2 = ((l2) ? l2->next : nullptr);
    }

    return sum->next;
}

int main()
{
    ListNode *node = addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4))));
    while (node)
    {
        std::cout << node->val << ' ';
        node = node->next;
    }
    return 0;
}