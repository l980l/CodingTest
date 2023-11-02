#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<vector<int>>> Board(N, vector<vector<int>>(M, vector<int>(H)));
	vector<vector<vector<int>>> Distance(N, vector<vector<int>>(M, vector<int>(H)));
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };
	int dz[2] = { 1,-1 };
	queue <tuple<int, int, int>> Queue;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int h = 0; h < M; ++h)
			{
				int a;
				cin >> a;
				Board[j][h][i] = a;
				// 초기부터 익은 토마토는 queue에 넣고 시작하자. 
				if (a == 1)
				{
					Queue.push({ j,h,i });	// tuple 헤더를 인클루드하니까 쓸 수 있음.
					Distance[j][h][i] = 0;
				}
				else
					Distance[j][h][i] = -1;
			}
		}
	}

	while (!Queue.empty())
	{
		int r, c, h;
		tie(r, c, h) = Queue.front();
		Queue.pop();

		// dx, dy
		for (int i = 0; i < 4; ++i)
		{
			int nx = r + dx[i];
			int ny = c + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			// 익지 않은 토마토인지만 검사해도 방문 여부도 판단할 수 있다. 
			if (Board[nx][ny][h] != 0)
				continue;
			Distance[nx][ny][h] = Distance[r][c][h] + 1;
			Board[nx][ny][h] = 1;
			Queue.push({ nx,ny,h });
		}
		// dz
		for (int i = 0; i < 2; ++i)
		{
			int nz = h + dz[i];

			if (nz < 0 || nz >= H)
				continue;
			// 익지 않은 토마토인지만 검사해도 방문 여부도 판단할 수 있다. 
			if (Board[r][c][nz] != 0)
				continue;
			Distance[r][c][nz] = Distance[r][c][h] + 1;
			Board[r][c][nz] = 1;
			Queue.push({ r,c,nz });
		}
	}

	int max = 0;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int h = 0; h < M; ++h)
			{
				if (Board[j][h][i] == 0)
				{
					cout << -1;
					return 0;
				}

				if (Distance[j][h][i] > max)
					max = Distance[j][h][i];
			}
		}
	}

	cout << max;

	return 0;
}