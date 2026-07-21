#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
vector<int> biIdx[8] = {{},{0, 1, 2, 3},{0, 2},{1, 3},{2, 3},{0, 3},{0, 1},{1, 2}};
int neighbor[4][4] = {{1,2,4,7}, {1,3,4,5}, {1,2,5,6}, {1,3,6,7}};

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, r, c, l;
    cin >> t;

    for (int tcn = 1; tcn <= t; ++tcn)
    {
        cin >> n >> m >> r >> c >> l;
        vector<vector<int>> board(n, vector<int>(m));
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> board[i][j];
            }
        }

        int result = 1;
        dist[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({ r,c });

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            if (dist[p.X][p.Y] == l)
                break;

            for (int i : biIdx[board[p.X][p.Y]])
            {
                int nx = p.X + dx[i];
                int ny = p.Y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1)
                    continue;

                for (int j = 0; j < 4; ++j)
                {
                    if (neighbor[i][j] == board[nx][ny])
                    {
                        dist[nx][ny] = dist[p.X][p.Y] + 1;
                        q.push({ nx,ny });
                        ++result;
                        break;
                    }
                }
            }
        }

        cout << "#" << tcn << " " << result << "\n";
    }

    return 0;
}