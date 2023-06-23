#include <bits/stdc++.h>

using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> tMap;

public:
    void set(string key, string value, int timestamp)
    {
        tMap[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp)
    {
        int left = 0, right = tMap[key].size() - 1, mid;
        string s{};
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (timestamp <= tMap[key][mid].first)
            {
                s = tMap[key][mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return s;
    }
};

int main()
{
    TimeMap tm;
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << endl;
    cout << tm.get("foo", 3) << endl;
    tm.set("foo", "bar2", 4);
    cout << tm.get("foo", 4) << endl;
    cout << tm.get("foo", 5) << endl;
    return 0;
}