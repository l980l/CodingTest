#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, a, b, l, result = 0;
    cin >> n >> m >> r;

    vector<int> itemCount(n);
    vector<vector<int>> board(n, vector<int>(n, 0x3f3f3f3f));
    
    for (int i = 0; i < n; ++i)
    {
        cin >> itemCount[i];
    }

    for (int i = 0; i < r; ++i)
    {
        cin >> a >> b >> l;

        board[a - 1][b - 1] = min(board[a - 1][b - 1], l);
        board[b - 1][a - 1] = min(board[b - 1][a - 1], l);
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                board[i][j] = min(board[i][k] + board[k][j], board[i][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int now = 0;
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] <= m || i == j)
                now += itemCount[j];
        }
        result = max(result, now);
    }

    cout << result;

    return 0;
}