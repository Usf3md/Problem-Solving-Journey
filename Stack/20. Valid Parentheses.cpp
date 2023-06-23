#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack<char> brackets;
    unordered_map<char, char> openBrackets{{'(', ')'}, {'[', ']'}, {'{', '}'}};
    unordered_map<char, char> closeBrackets{{')', '('}, {']', '['}, {'}', '{'}};
    for (auto &el : s)
    {
        if (openBrackets.count(el))
        {
            brackets.push(el);
            continue;
        }
        else if (brackets.empty() || closeBrackets[el] != brackets.top())
        {
            return false;
        }
        brackets.pop();
    }
    if (!brackets.empty())
        return false;
    return true;
}

int main()
{
    cout << isValid("]");
    return 0;
}