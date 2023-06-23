#include <bits/stdc++.h>

using namespace std;

void generator(int n, string s, vector<string> &output)
{
    if (!n)
    {
        stack<char> st;
        for (auto &el : s)
        {
            if (el == '(')
                st.push(el);
            else if (!st.empty())
                st.pop();
            else
                return;
        }
        if (st.empty())
            output.push_back(s);
    }
    else
    {
        generator(n - 1, s + '(', output);
        generator(n - 1, s + ')', output);
    }
}

int main()
{
    vector<string> output;
    int n = 3;
    generator(n * 2, "", output);
    for (auto &el : output)
    {
        cout << el << endl;
    }
    return 0;
}