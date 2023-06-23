#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> m;
    for (auto &el : nums)
    {
        m[el]++;
    }

    for (auto &el : m)
    {
        pq.push({el.second, el.first});
    }

    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    for (auto &el : topKFrequent(nums, 3))
    {
        cout << el << ' ';
    }
    return 0;
}