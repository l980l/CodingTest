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

	vector<vector<int>> Board(N, vector<int>(M));
	vector<vector<int>> Distance(N, vector<int>(M));

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; ++j)
		{
			Distance[i][j] = -1;
			Board[i][j] = S[j] - '0';
		}
	}

	queue<pair<int, int>> Queue;

	Queue.push({ 0,0 });
	Distance[0][0] = 1;

	while (!Queue.empty())
	{
		pair<int, int> Pair = Queue.front();
		Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = Pair.first + dx[i];
			int ny = Pair.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (!Board[nx][ny] || Distance[nx][ny] != -1)
				continue;
			Queue.push({ nx, ny });
			Distance[nx][ny] = Distance[Pair.first][Pair.second] + 1;
		}
	}

	cout << Distance[N - 1][M - 1];

	return 0;
}