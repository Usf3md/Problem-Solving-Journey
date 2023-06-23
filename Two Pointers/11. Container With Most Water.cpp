#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height)
{
    int mx = INT_MIN;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
        while (j > i)
        {
            mx = max(mx, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
    }
    return mx;
}

int main()
{

    return 0;
}