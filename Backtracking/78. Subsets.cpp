#include <bits/stdc++.h>

using namespace std;

void generator(vector<int> &nums, vector<vector<int>> &res, vector<int> subset, int count)
{
    for (int i = count; i < nums.size(); i++)
    {
        subset.push_back(nums[i]);
        res.push_back(subset);
        generator(nums, res, subset, i + 1);
        subset.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res{{}};
    vector<int> subset;
    generator(nums, res, subset, 0);
    return res;
}

int main()
{
    vector<int> nums{1, 2, 3};
    for (auto &x : subsets(nums))
    {
        for (auto &y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << endl;
    }
    return 0;
}