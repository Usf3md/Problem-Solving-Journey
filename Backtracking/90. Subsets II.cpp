#include <bits/stdc++.h>

using namespace std;

void generator(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int index)
{
    if (index >= nums.size())
    {
        res.push_back(subset);
        return;
    }

    subset.push_back(nums[index]);
    generator(nums, res, subset, index + 1);
    subset.pop_back();
    while (index + 1 < nums.size() and nums[index] == nums[index + 1])
    {
        index++;
    }
    generator(nums, res, subset, index + 1);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<int> found;
    vector<vector<int>> res{};
    vector<int> subset;
    sort(nums.begin(), nums.end());
    generator(nums, res, subset, 0);
    return res;
}

int main()
{
    vector<int> nums{1, 2, 2};
    for (auto &x : subsetsWithDup(nums))
    {
        for (auto &y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << endl;
    }
    return 0;
}