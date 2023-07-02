#include <bits/stdc++.h>

using namespace std;

void generator(vector<int> &nums, vector<vector<int>> &res, vector<int> subset, set<int> &currentNums)
{
    if (subset.size() == nums.size())
    {
        res.push_back(subset);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (currentNums.count(nums[i]))
            continue;

        subset.push_back(nums[i]);
        currentNums.insert(nums[i]);
        generator(nums, res, subset, currentNums);
        subset.pop_back();
        currentNums.erase(nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> subset;
    set<int> currentNums;
    generator(nums, res, subset, currentNums);
    return res;
}

int main()
{
    vector<int> nums{1, 2, 3};
    for (auto &x : permute(nums))
    {
        for (auto &y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << endl;
    }
    return 0;
}