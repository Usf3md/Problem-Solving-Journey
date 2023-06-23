#include <bits/stdc++.h>

using namespace std;

int xorOperation(int n, int start)
{
    int sum = start;
    for (int i = 1; i < n; i++)
    {
        sum ^= start + 2 * i;
    }
    return sum;
}

int main()
{
    cout << xorOperation(5, 0);
    return 0;
}