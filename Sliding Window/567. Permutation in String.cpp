#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    map<char, int> m;
    for (auto &el : s1)
        m[el]++;

    int i = 0, j = 0;
    char debugJ;
    char debugI;
    while (j < s2.length())
    {
        if (m.count(s2[j]))
        {
            if (m[s2[j]])
            {
                m[s2[j]]--;
                if (s1.length() == j - i + 1)
                {
                    return true;
                }
                j++;
            }
            else
            {
                m[s2[i]]++;
                i++;
            }
        }
        else
        {
            while (i < j)
            {
                m[s2[i]]++;
                i++;
            }
            i++;
            j++;
        }
    }
    return false;
}

int main()
{
    std::cout << checkInclusion("ab", "eidbaooo");
    return 0;
}