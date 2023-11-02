#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	// 시작 위치랑 끝 위치에서 각각 BFS를 구할 것이다.
	vector<vector<int>> Board(N, vector<int>(M));
	vector<vector<int>> SDistance(N, vector<int>(M));
	vector<vector<int>> EDistance(N, vector<int>(M));
	// 벽을 부수고 간 경우의 거리. 근데 이 거리행렬은 해당 벽을 부수고 갔을 경우의 최종 거리 행렬이다. 다른 행렬은 해당 위치까지의 거리라서 의미가 다름.
	vector<vector<int>> BreakWallDistance(N, vector<int>(M));	
	queue<pair<int, int>> SQueue;
	queue<pair<int, int>> EQueue;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			Board[i][j] = S[j] - '0';
			SDistance[i][j] = -1;
			EDistance[i][j] = -1;
			BreakWallDistance[i][j] = -1;
		}
	}

	SDistance[0][0] = 1;
	EDistance[N-1][M-1] = 1;

	SQueue.push({ 0,0 });
	EQueue.push({ N - 1,M - 1 });

	// 출발 위치로부터의 BFS
	while (!SQueue.empty())
	{
		auto Pair = SQueue.front();
		SQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = Pair.first + dx[i];
			int ny = Pair.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (SDistance[nx][ny] != -1 || Board[nx][ny] != 0)
				continue;

			SDistance[nx][ny] = SDistance[Pair.first][Pair.second] + 1;
			SQueue.push({ nx, ny });
		}
	}

	// 도착 위치로부터의 BFS
	while (!EQueue.empty())
	{
		auto Pair = EQueue.front();
		EQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = Pair.first + dx[i];
			int ny = Pair.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (EDistance[nx][ny] != -1)
				continue;
			// 벽인 경우에는 벽에서 또다시 한칸씩 탐색해서 SDistance가 -1이 아닌지 확인하고 -1아니라면 부실 수 있는 벽이다. 이는 따로 BreakWallDistance에 저장한다. 
			if (Board[nx][ny] != 0)
			{
				for (int i = 0; i < 4; ++i)
				{
					int nx2 = nx + dx[i];
					int ny2 = ny + dy[i];

					if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M)
						continue;
					// 벽인 경우 
					if (SDistance[nx2][ny2] == -1)
						continue;
					// 왔던 곳 경우
					if (nx2 == Pair.first && ny2 == Pair.second)
						continue;
					// 출발 위치로부터 벽까지의 거리 + 도착 위치로부터 벽까지의 거리 + 1. 이전에 구해둔 값이 있는 경우, 더 작은 값으로 변경.
					if (BreakWallDistance[nx][ny] == -1)
						BreakWallDistance[nx][ny] = SDistance[nx2][ny2] + EDistance[Pair.first][Pair.second] + 1;
					else if (BreakWallDistance[nx][ny] > SDistance[nx2][ny2] + EDistance[Pair.first][Pair.second] + 1)
						BreakWallDistance[nx][ny] = SDistance[nx2][ny2] + EDistance[Pair.first][Pair.second] + 1;
				}
			}

			else
			{
				EDistance[nx][ny] = EDistance[Pair.first][Pair.second] + 1;
				EQueue.push({ nx, ny });
			}
		}
	}

	int Result = -1;

	if (SDistance[N - 1][M - 1] != -1)
		Result = SDistance[N - 1][M - 1];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (BreakWallDistance[i][j] != -1)
			{
				if(Result == -1)
					Result = BreakWallDistance[i][j];
				else if(Result > BreakWallDistance[i][j])
					Result = BreakWallDistance[i][j];
			}
		}
	}

	cout << Result;

	return 0;
}