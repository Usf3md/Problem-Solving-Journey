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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> nodes;
    if (root)
        nodes.push(root);

    while (!nodes.empty())
    {

        int size = nodes.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            temp.push_back(nodes.front()->val);
            if (nodes.front()->left)
                nodes.push(nodes.front()->left);
            if (nodes.front()->right)
                nodes.push(nodes.front()->right);
            nodes.pop();
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{

    return 0;
}