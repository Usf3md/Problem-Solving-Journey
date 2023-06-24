#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> found;
    int mx = 0;
    int i = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (!found.count(s[j]))
            found.insert(s[j]);
        else
        {
            while (found.count(s[j]))
            {
                found.erase(s[i++]);
            }
            found.insert(s[j]);
        }
        mx = max(mx, (int)found.size());
    }
    return mx;
}

int main()
{
    std::cout << lengthOfLongestSubstring("dvdf");
    return 0;
}