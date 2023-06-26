#include <bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k)
{
    int i = 0, j = 0;
    map<char, int> m;
    int mx = 0, maxLetter = 0;
    for (int j = 0; j < s.length(); j++)
    {
        m[s[j]]++;
        maxLetter = max(maxLetter, m[s[j]]);
        if ((j - i + 1 - maxLetter) > k)
        {
            m[s[i]]--;
            i++;
        }
        mx = max(mx, j - i + 1);
    }

    return mx;
}

int main()
{
    cout << characterReplacement("ABAA", 0);
    return 0;
}