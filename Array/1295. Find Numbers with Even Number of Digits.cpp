#include <bits/stdc++.h>

using namespace std;

int findNumbers(vector<int> &nums)
{
    int counter;
    int answer = 0;
    for (auto &el : nums)
    {
        counter = 0;
        while (el >= 10)
        {
            el /= 10;
            counter++;
        }
        if (counter % 2)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{

    return 0;
}