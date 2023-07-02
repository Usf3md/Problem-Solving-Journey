#include <bits/stdc++.h>

using namespace std;

void generator(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int &target, int sum, int index)
{
    if (sum == target)
    {
        res.push_back(subset);
        return;
    }

    else if (sum > target)
        return;

    for (int i = index; i < nums.size(); i++)
    {
        subset.push_back(nums[i]);
        generator(nums, res, subset, target, sum + nums[i], i);
        subset.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> subset;
    generator(candidates, res, subset, target, 0, 0);
    return res;
}

int main()
{
    vector<int> nums{2, 3, 6, 7};
    for (auto &x : combinationSum(nums, 7))
    {
        for (auto &y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << endl;
    }
    return 0;
}