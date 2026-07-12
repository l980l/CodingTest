#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int at[] = { 3, 2, 1 };

#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    pair<int, int> st, en;

    cin >> t;

    for (int tcn = 1; tcn <= t; ++tcn)
    {
        cin >> n;

        const int INF = 0x3f3f3f3f;
        vector<vector<int>> board(n, vector<int>(n));
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> board[i][j];
            }
        }

        cin >> st.X >> st.Y;
        cin >> en.X >> en.Y;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        cost[st.X][st.Y] = 0;
        pq.push({ 0, st.X,st.Y });

        while (!pq.empty())
        {
            int c, x, y;
            tie(c, x, y) = pq.top();
            pq.pop();

            if (x == en.X && y == en.Y)
                break;

            if (c != cost[x][y])
                continue;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1)
                    continue;

                if (board[nx][ny] == 2)
                {
                    if (cost[nx][ny] > c + at[c % 3])
                    {
                        cost[nx][ny] = c + at[c % 3];
                        pq.push({ c + at[c % 3],nx,ny });
                    }
                }
                else if(cost[nx][ny]>c+1)
                {
                    cost[nx][ny] = c + 1;
                    pq.push({ c + 1,nx,ny });
                }
            }
        }

        cout << '#' << tcn << ' ' << ((cost[en.X][en.Y] == INF) ? -1 : cost[en.X][en.Y]) << '\n';
    }

    return 0;
}