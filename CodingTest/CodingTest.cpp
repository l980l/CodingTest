#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N, M, K;
vector<string> board;
unordered_map<string, int> strings;

int dx[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, -1, 1 };

void func(int x, int y, string madeStr)
{
    ++strings[madeStr];
    if (madeStr.size() >= 5)
        return;
    for (int i = 0; i < 8; ++i)
    {
        int nx = (x + dx[i] + N) % N;
        int ny = (y + dy[i] + M) % M;
        func(nx, ny, madeStr + board[nx][ny]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    board = vector<string>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }

    string madeStr;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            madeStr = board[i][j];
            func(i, j, madeStr);
        }
    }

    while (K--)
    {
        string temp;
        cin >> temp;

        cout << strings[temp] << '\n';
    }

    return 0;
}