#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = i + 1, k = nums.size() - 1;
    int sum, temp, diff = INT_MAX;
    while (i < nums.size() - 2)
    {
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {
            temp = nums[i] + nums[j] + nums[k];
            if (abs(target - temp) < diff)
            {
                diff = abs(target - temp);
                sum = temp;
            }
            if (temp < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
        i++;
    }
    return sum;
}

int main()
{
    vector<int> nums{-1, 2, 1, -4};
    cout << threeSumClosest(nums, 1);

    return 0;
}