#include <bits/stdc++.h>

using namespace std;

bool generator(vector<vector<char>> &board, set<string> &path, string word, int i, int j, int letterIndex)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || path.count(to_string(i) + "|" + to_string(j)))
        return false;

    if (word[letterIndex] != board[i][j])
        return false;

    if (letterIndex == word.size() - 1)
        return true;

    path.insert(to_string(i) + "|" + to_string(j));
    if (generator(board, path, word, i + 1, j, letterIndex + 1) ||
        generator(board, path, word, i - 1, j, letterIndex + 1) ||
        generator(board, path, word, i, j + 1, letterIndex + 1) ||
        generator(board, path, word, i, j - 1, letterIndex + 1))
        return true;
    path.erase(to_string(i) + "|" + to_string(j));
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    set<string> path;
    map<char, int> freq;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            freq[board[i][j]]++;
        }
    }

    if (freq[word[word.size() - 1]] < freq[word[0]])
        reverse(word.begin(), word.end());

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (generator(board, path, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    cout << exist(board, word);
    return 0;
}