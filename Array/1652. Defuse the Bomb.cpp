#include <bits/stdc++.h>

using namespace std;

vector<int> decrypt(vector<int> &code, int k)
{
    vector<int> sum = vector<int>(code.size(), 0);
    if (!k)
    {
        return sum;
    }
    int neg = 1;
    if (k < 0)
    {
        k *= -1;
        neg = -1;
    }
    for (int i = 0; i < code.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum[i] += code[((i + (j + 1) * neg) + code.size()) % code.size()];
        }
    }
    return sum;
}

int main()
{
    vector<int> code = {10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6};
    for (auto &el : decrypt(code, -4))
    {
        cout << el << ' ';
    }
    return 0;
}