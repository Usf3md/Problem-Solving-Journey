#include <bits/stdc++.h>

using namespace std;

bool checkSufficientAmount(vector<int> &piles, int h, int amount)
{
    int sum = 0;
    for (auto &el : piles)
    {
        sum += ceil((long double)el / amount);
    }
    return sum <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int maximumPile = INT_MIN;
    for (auto &pile : piles)
        maximumPile = max(maximumPile, pile);

    int left = 0, right = maximumPile, mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (checkSufficientAmount(piles, h, mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return right;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    cout << minEatingSpeed(piles, 8);
    return 0;
}