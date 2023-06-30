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

bool sameTree(TreeNode *root, TreeNode *subRoot)
{
    if (!root && !subRoot)
        return true;
    if (!root || !subRoot)
        return false;

    return root->val == subRoot->val && sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root)
        return false;

    if (root->val == subRoot->val && sameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{

    return 0;
}