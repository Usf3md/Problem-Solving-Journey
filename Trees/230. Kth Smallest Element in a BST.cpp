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

void dfs(TreeNode *root, int &k, vector<int> &res)
{
    if (!root || res.size() >= k)
        return;
    dfs(root->left, k, res);
    res.push_back(root->val);
    dfs(root->right, k, res);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> res;
    dfs(root, k, res);
    return res[k - 1];
}

int main()
{

    return 0;
}