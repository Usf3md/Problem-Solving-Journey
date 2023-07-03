#include <bits/stdc++.h>

using namespace std;

void generator(vector<int> &nums, vector<vector<int>> &res, vector<int> subset, int target, int sum, int index)
{
    if (sum == target)
    {
        res.push_back(subset);
        return;
    }
    else if (sum > target)
        return;

    int prev = -1;
    for (int i = index; i < nums.size(); i++)
    {
        if (nums[i] == prev)
            continue;
        subset.push_back(nums[i]);
        generator(nums, res, subset, target, sum + nums[i], i + 1);
        subset.pop_back();
        prev = nums[i];
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> subset;
    sort(candidates.begin(), candidates.end());
    generator(candidates, res, subset, target, 0, 0);
    return res;
}

int main()
{
    vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    for (auto &x : combinationSum2(nums, 8))
    {
        for (auto &y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << endl;
    }
    return 0;
}