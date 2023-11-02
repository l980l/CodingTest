#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[8] = { 1,2,2,1,-1,-2,-2, -1 };
	int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<vector<int>> Distance(n, vector<int>(n));
		queue<pair<int, int>> Queue;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				Distance[i][j] = -1;
			}
		}
		// 나이트의 초기 위치
		int x, y;
		cin >> x >> y;
		Distance[x][y] = 0;
		Queue.push({ x,y });
		while (!Queue.empty())
		{
			auto Pair = Queue.front();
			Queue.pop();

			for (int i = 0; i < 8; ++i)
			{
				int nx = Pair.first + dx[i];
				int ny = Pair.second + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (Distance[nx][ny] != -1)
					continue;
				Distance[nx][ny] = Distance[Pair.first][Pair.second] + 1;
				Queue.push({ nx,ny });
			}
		}
		// 나이트의 목적 위치
		cin >> x >> y;
		cout << Distance[x][y] << "\n";
	}

	return 0;
}