#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> nums;
    int a, b, res;
    for (auto &el : tokens)
    {
        if (isdigit(el[0]) || el.length() > 1)
            nums.push(stoi(el));
        else
        {
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            switch (el[0])
            {
            case '+':
                res = b + a;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = b * a;
                break;
            case '/':
                res = b / a;
                break;
            }
            nums.push(res);
        }
    }
    return nums.top();
}

int main()
{
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << evalRPN(tokens);
    return 0;
}