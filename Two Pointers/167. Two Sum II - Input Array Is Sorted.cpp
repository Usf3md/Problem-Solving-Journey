#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j)
    {
        while (j > i)
        {
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
            else if (numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
        }
    }
    return {-1, -1};
}

int main()
{

    return 0;
}