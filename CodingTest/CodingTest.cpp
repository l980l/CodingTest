#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> copyboard;
vector<pair<int, int>> blank;
queue<pair<int, int>> virus;
int Result = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void BFS()
{
	queue<pair<int, int>> copyvirus = virus;

	while (!copyvirus.empty())
	{
		auto pair = copyvirus.front();
		copyvirus.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pair.first + dx[i];
			int ny = pair.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (copyboard[nx][ny] == 1 || copyboard[nx][ny] == 2)
				continue;
			copyboard[nx][ny] = 2;
			copyvirus.push(make_pair(nx, ny));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int x;
			cin >> x;
			board[i][j] = x;
			if (x == 0)
				blank.push_back(make_pair(i, j));
			else if (x == 2)
				virus.push(make_pair(i, j));
		}
	}

	int size = blank.size();

	vector<int> Wall(size);

	Wall[size - 3] = 1;
	Wall[size - 2] = 1;
	Wall[size - 1] = 1;

	do
	{
		copyboard = board;
		for (int i = 0; i < size; ++i)
		{
			if (Wall[i])
			{
				copyboard[blank[i].first][blank[i].second] = 1;
			}
		}
		BFS();
		// copyboard에서 0번 개수 찾기
		int NowResult = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (copyboard[i][j] == 0)
					NowResult++;
			}
		}

		Result = max(Result, NowResult);
	} while (next_permutation(Wall.begin(), Wall.end()));

	cout << Result;

	return 0;
}