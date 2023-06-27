#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;
    int firstMap[26]{};
    int secondMap[26]{};

    int i = 0, j = 0;
    for (j = 0; j < s1.length(); j++)
    {
        firstMap[s1[j] - 97]++;
        secondMap[s2[j] - 97]++;
    }

    int matches = 0;
    for (int k = 0; k < 26; k++)
        if (firstMap[k] == secondMap[k])
            matches++;

    while (j < s2.length())
    {
        if (matches == 26)
            return true;
        if (secondMap[s2[i] - 97] == firstMap[s2[i] - 97])
            matches--;
        secondMap[s2[i] - 97]--;
        if (secondMap[s2[i] - 97] == firstMap[s2[i] - 97])
            matches++;
        i++;
        if (secondMap[s2[j] - 97] == firstMap[s2[j] - 97])
            matches--;
        secondMap[s2[j] - 97]++;
        if (secondMap[s2[j] - 97] == firstMap[s2[j] - 97])
            matches++;
        j++;
        if (matches == 26)
            return true;
    }
    return false;
}

int main()
{
    std::cout << checkInclusion("ab", "eidbaooo");
    return 0;
}