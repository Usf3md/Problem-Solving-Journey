#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    int fast = 0, slow = 0;

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (fast != slow);

    int slow2 = 0;
    while (slow != slow2)
    {
        slow = nums[slow];
        slow2 = nums[slow2];
    }

    return slow;
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};
    cout << findDuplicate(nums);
    return 0;
}