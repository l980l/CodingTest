#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rot(vector<vector<int>>& board, int N)
{
    vector<vector<int>> temp = board;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = temp[N - 1 - j][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;

    for (int tcn = 1; tcn <= T; ++tcn)
    {
        cin >> N;

        vector<vector<int>> board(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> board[i][j];
            }
        }

        vector<vector<vector<int>>> result;
        for (int i = 0; i < 3; ++i)
        {
            rot(board, N);
            result.push_back(board);
        }

        cout << '#' << tcn << '\n';
        for (int r = 0; r < N; ++r)
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int c = 0; c < N; ++c)
                {
                    cout << result[i][r][c];
                }
                cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}