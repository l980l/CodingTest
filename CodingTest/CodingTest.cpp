#include <iostream>	
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	vector<vector<int>> Board(N, vector<int>(M));
	vector<vector<int>> Distance(N, vector<int>(M));
	queue<pair<int, int>> Queue;

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int a;
			cin >> a;

			Board[i][j] = a;
			Distance[i][j] = 0;

			// 초기부터 익은 토마토를 Queue에 넣어버리기.
			if(a==1)
				Queue.push({ i,j });
		}
	}

	while (!Queue.empty())
	{
		pair<int, int> Pair = Queue.front();
		Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = Pair.first + dx[i];
			int ny = Pair.second + dy[i];

			int curx = Pair.first;
			int cury = Pair.second;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (Board[nx][ny] == -1)
				continue;
			// 생각해보니 애초에 방문했으면 1임.
			if (Board[nx][ny] == 0)
			{
				Board[nx][ny] = 1;
				Distance[nx][ny] = Distance[curx][cury] + 1;
				Queue.push({ nx,ny });
			}
		}
	}

	int Result = -1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Board[i][j] == -1)
				continue;

			if (Board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			
			if (Result < Distance[i][j])
				Result = Distance[i][j];
		}
	}

	cout << Result;

	return 0;
}