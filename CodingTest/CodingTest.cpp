#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;

	vector<vector<int>> Board(R, vector<int>(C));
	vector<vector<int>> JDistance(R, vector<int>(C));	// 지훈이로부터의 거리
	vector<vector<int>> FDistance(R, vector<int>(C));	// 불로부터의 거리
	queue<pair<int, int>> JQueue;
	queue<pair<int, int>> FQueue;
	int dx[4] = { 0,1,-1,0 };
	int dy[4] = { 1,0,0,-1 };


	for (int i = 0; i < R; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < C; ++j)
		{
			Board[i][j] = S[j];

			// 지훈이의 초기 위치
			if (S[j] == 'J')
			{
				JDistance[i][j] = 0;
				FDistance[i][j] = 1e9;
				JQueue.push({ i,j });
			}
			// 불의 초기 위치
			else if (S[j] == 'F')
			{
				FDistance[i][j] = 0;
				JDistance[i][j] = 1e9;
				FQueue.push({ i,j });
			}
			else
			{
				JDistance[i][j] = 1e9;
				FDistance[i][j] = 1e9;
			}
		}
	}

	// 지훈이로 BFS
	while (!JQueue.empty())
	{
		pair<int, int> Pair = JQueue.front();
		JQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = Pair.first + dx[i];
			int ny = Pair.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			// 길이 아닌 경우
			if (Board[nx][ny] != '.')
				continue;
			// 이미 방문한 길인 경우
			if (JDistance[nx][ny] != 1e9)
				continue;
			
			JDistance[nx][ny] = JDistance[Pair.first][Pair.second] + 1;
			JQueue.push({ nx,ny });
		}
	}

	// 불로 BFS
	while (!FQueue.empty())
	{
		pair<int, int> Pair = FQueue.front();
		FQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = Pair.first + dx[i];
			int ny = Pair.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			// 길이 아닌 경우
			if (Board[nx][ny] != '.')
				continue;
			// 이미 방문한 길인 경우
			if (FDistance[nx][ny] != 1e9)
				continue;

			FDistance[nx][ny] = FDistance[Pair.first][Pair.second] + 1;
			FQueue.push({ nx,ny });
		}
	}

	int Result = 1e9;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (i == 0 || j == 0 || i == R - 1 || j == C - 1)
			{
				// 나가는 쪽인 경우.
				if (Board[i][j] == '.' || Board[i][j] == 'J')
				{
					// 지훈이로부터 더 가까운 길 중에 최소 길이
					if (JDistance[i][j] < FDistance[i][j] && Result > JDistance[i][j])
						Result = JDistance[i][j];
				}
			}
		}
	}

	if (Result >= 1e9)
		cout << "IMPOSSIBLE";
	else
		cout << Result + 1;

	return 0;
}