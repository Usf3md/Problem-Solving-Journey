#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int i = 0, j, k = nums.size(), sum;
    while (i <= nums.size() - 2)
    {
        if (nums[i] > 0)
        {
            break;
        }
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (nums[j] == nums[j - 1] && j < k)
                {
                    j++;
                }
            }
            else if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
        }
        i++;
        while (nums[i] == nums[i - 1] && i < nums.size() - 2)
        {
            i++;
        }
    }
    return result;
}
int main()
{
    vector<int> nums{0, 0, 0, 0};
    for (auto el : threeSum(nums))
    {
        for (auto e : el)
        {
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}