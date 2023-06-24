#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int mx = 0;
    int smallestFound = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < smallestFound)
            smallestFound = prices[i];
        mx = max(mx, prices[i] - smallestFound);
    }
    return mx;
}

int main()
{
    vector<int> nums{7, 1, 5, 3, 6, 4};
    std::cout << maxProfit(nums);
    return 0;
}