#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto &el : nums)
        {
            if (s.count(el))
            {
                return true;
            }
            s.insert(el);
        }
        return false;
    }
};

int main()
{

    return 0;
}