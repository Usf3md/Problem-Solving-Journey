#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid;
    if (nums[left] == target)
    {
        return left;
    }
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] >= nums[left])
        {
            if (target <= nums[mid] && target >= nums[left])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (nums[mid] <= nums[right])
        {
            if (target >= nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{1, 3};
    cout << search(nums, 3);
    return 0;
}