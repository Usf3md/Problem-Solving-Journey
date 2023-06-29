#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<pair<int, int>> s;
    vector<int> res(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!s.empty() && s.top().first < temperatures[i])
        {
            res[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({temperatures[i], i});
    }
    return res;
}

int main()
{
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    for (auto &el : dailyTemperatures(temperatures))
    {
        std::cout << el << ' ';
    }
    return 0;
}