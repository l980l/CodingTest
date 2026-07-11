#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int dx[] = { 1,0,-1,0,1,1,-1,-1 };
int dy[] = { 0,-1,0,1,1,-1,1,-1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    for (int tcn = 1; tcn <= t; ++tcn)
    {
        cin >> n;

        vector<string> board(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> board[i];
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == '*')
                {
                    for (int k = 0; k < 8; ++k)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] != '.')
                            continue;
                     
                        board[nx][ny] = 'b';
                    }
                }
            }
        }

        vector<vector<bool>> visit(n, vector<bool>(n));
        queue<pair<int, int>> q;
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == '.' && visit[i][j] == false)
                {
                    ++count;
                    q.push({ i,j });
                    visit[i][j] = true;

                    while (!q.empty())
                    {
                        auto p = q.front();
                        q.pop();

                        for (int k = 0; k < 8; ++k)
                        {
                            int nx = p.X + dx[k];
                            int ny = p.Y + dy[k];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == '*' || visit[nx][ny])
                                continue;

                            visit[nx][ny] = true;

                            if(board[nx][ny] == '.')
                                q.push({ nx,ny });
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'b' && visit[i][j] == false)
                    ++count;
            }
        }

        cout << '#' << tcn << ' ' << count << '\n';
    }

    return 0;
}