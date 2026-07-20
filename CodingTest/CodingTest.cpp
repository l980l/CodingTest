#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

#define X first
#define Y second

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	for (int tcn = 1; tcn <= t; ++tcn)
	{
		cin >> n;
		vector<vector<int>> board(n, vector<int>(n));
		vector<vector<bool>> visit(n,vector<bool>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> board[i][j];
			}
		}

		int maxSize = 0;
		int roomNum = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visit[i][j])
					continue;
				visit[i][j] = true;
				q.push({ i, j });
				int curSize = 1;
				int curRN = board[i][j];

				while (!q.empty())
				{
					auto p = q.front();
					int rn = board[p.X][p.Y];
					q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = p.X + dx[dir];
						int ny = p.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny])
							continue;
						if (board[nx][ny] + 1 != rn && board[nx][ny] - 1 != rn)
							continue;
						
						if (board[nx][ny] + 1 == rn)
							curRN = rn - 1;

						++curSize;
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}

				if (maxSize < curSize)
				{
					maxSize = curSize;
					roomNum = curRN;
				}
				else if (maxSize == curSize && roomNum > curRN)
				{
					roomNum = curRN;
				}
			}
		}

		cout << "#" << tcn << " " << roomNum << " " << maxSize << "\n";
	}

	return 0;
}
