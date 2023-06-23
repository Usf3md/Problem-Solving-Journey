#include <bits/stdc++.h>

using namespace std;

class MinStack
{
public:
    deque<pair<int, int>> s;
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push_back({val, val});
        }
        else
        {
            s.push_back({val, min(val, s.back().second)});
        }
    }

    void pop()
    {
        s.pop_back();
    }

    int top()
    {
        return s.back().first;
    }

    int getMin()
    {
        return s.back().second;
    }
};