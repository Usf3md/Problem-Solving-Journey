#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, mid;
    // int res = INT_MIN;
    if (nums[left] < nums[right])
    {
        return nums[left];
    }
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] >= nums[left])
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return nums[right];
}

int main()
{
    vector<int> nums{8, 4, 5, 6, 7};
    cout << findMin(nums);
    return 0;
}