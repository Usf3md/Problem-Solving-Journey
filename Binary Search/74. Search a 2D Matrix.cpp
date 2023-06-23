#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int left = 0, right = matrix.size() - 1, mid;

    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (matrix[mid][matrix[mid].size() - 1] < target)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    int row = ((matrix[0][matrix[0].size() - 1] >= target) ? left : right);
    left = 0, right = matrix[row].size() - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] < target)
            left = mid + 1;
        else if (matrix[row][mid] > target)
            right = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    matrix = {{1}, {3}};
    cout << searchMatrix(matrix, 1);
    return 0;
}