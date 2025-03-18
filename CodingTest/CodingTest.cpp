#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };;
int dy[] = { 0, -1, 0, 1 };;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;
    vector<vector<int>> board(N);

    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;

        for (char c : temp)
        {
            int cur = (int)c - '0';
            board[i].push_back(cur);
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<int>> d(N, vector<int>(M, 0x3f3f3f3f));
    d[0][0] = 0;

    pq.push({ 0, 0, 0 });
    int c, x, y;
    while (pq.empty() == false)
    {
        tie(c, x, y) = pq.top();
        pq.pop();

        if (c != d[x][y])
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (d[nx][ny] <= d[x][y] + board[nx][ny])
                continue;

            d[nx][ny] = d[x][y] + board[nx][ny];
            pq.push({ d[nx][ny], nx, ny });
        }
    }

    cout << d[N - 1][M - 1];

    return 0;
}