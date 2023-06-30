#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *ptr = root;
    while (ptr)
    {
        if (ptr->val > p->val && ptr->val > q->val)
            ptr = ptr->left;
        else if (ptr->val < p->val && ptr->val < q->val)
            ptr = ptr->right;
        else
            return ptr;
    }
    return nullptr;
}

int main()
{

    return 0;
}