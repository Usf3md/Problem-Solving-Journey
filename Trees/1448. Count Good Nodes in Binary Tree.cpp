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

int getGoodNodes(TreeNode *root, int mx)
{
    if (!root)
        return 0;

    return ((root->val >= mx) ? 1 : 0) + getGoodNodes(root->left, max(mx, root->val)) + getGoodNodes(root->right, max(mx, root->val));
}
int goodNodes(TreeNode *root)
{
    return getGoodNodes(root, INT_MIN);
}

int main()
{

    return 0;
}