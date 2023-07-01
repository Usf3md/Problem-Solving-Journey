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

bool checker(TreeNode *root, long long int smallestRange, long long int largestRange)
{
    if (!root)
        return true;

    return root->val > smallestRange &&
           root->val < largestRange &&
           checker(root->left, smallestRange, root->val) &&
           checker(root->right, root->val, largestRange);
}

bool isValidBST(TreeNode *root)
{
    return checker(root, LLONG_MIN, LLONG_MAX);
}

int main()
{

    return 0;
}