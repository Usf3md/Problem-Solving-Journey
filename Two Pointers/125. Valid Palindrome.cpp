#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    string cleanString;
    for (auto &el : s)
    {
        if (isalnum(el))
            cleanString += tolower(el);
    }
    int i = 0;
    int j = cleanString.length() - 1;
    cout << cleanString;
    while (i <= j)
    {
        if (cleanString[i++] != cleanString[j--])
            return false;
    }
    return true;
}

int main()
{
    cout << isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}