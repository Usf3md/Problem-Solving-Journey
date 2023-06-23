#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums{5};
    int target = 5;
    int left = 0, right = nums.size() - 1, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (target == nums[mid])
        {
            cout << mid;
            return 0;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << -1;
}
