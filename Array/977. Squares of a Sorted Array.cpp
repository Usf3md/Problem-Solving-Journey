#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int left = 0;
    int right = nums.size();
    int mid;
    while (left + 1 < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < 0)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    vector<int> mergedSquare;
    while (left >= 0 && right < nums.size())
    {
        if ((nums[left] * -1) < nums[right])
        {
            mergedSquare.push_back(nums[left] * nums[left]);
            left--;
        }
        else
        {
            mergedSquare.push_back(nums[right] * nums[right]);
            right++;
        }
    }
    while (left >= 0)
    {
        mergedSquare.push_back(nums[left] * nums[left]);
        left--;
    }
    while (right < nums.size())
    {
        mergedSquare.push_back(nums[right] * nums[right]);
        right++;
    }
    return mergedSquare;
}