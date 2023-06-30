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

int dfs(TreeNode *root, int &mx)
{
    if (!root)
        return -1;
    int left = dfs(root->left, mx);
    int right = dfs(root->right, mx);
    mx = max(mx, left + right + 2);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    int mx = 0;
    dfs(root, mx);
    return mx;
}

int main()
{

    return 0;
}