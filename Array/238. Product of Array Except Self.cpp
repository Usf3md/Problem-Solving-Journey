#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> result(nums.size(), 1);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        result[i + 1] = result[i] * nums[i];
    }
    int temp = 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        temp *= nums[i + 1];
        result[i] *= temp;
    }
    return result;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    for (auto &el : productExceptSelf(nums))
    {
        cout << el << " ";
    }
    return 0;
}