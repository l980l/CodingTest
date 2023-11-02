#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, M, N, K;
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		vector <vector<int>> Board(N, vector<int>(M));
		vector <vector<int>> Visit(N, vector<int>(M));
		int dx[4] = { 0,1,-1,0 };
		int dy[4] = { 1,0,0,-1 };

		for (int i = 0; i < K; ++i)
		{
			int X, Y;
			cin >> X >> Y;

			Board[Y][X] = 1;
			Visit[Y][X] = 0;
		}

		int Result = 0;

		queue<pair<int, int>> Queue;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				// 방문하지 않은 배추.
				if (Board[i][j] == 1 && Visit[i][j] == 0)
				{
					Result++;
					Queue.push({ i,j });
					Visit[i][j] = 1;
					while (!Queue.empty())
					{
						auto Pair = Queue.front();
						Queue.pop();

						for (int i = 0; i < 4; ++i)
						{
							int nx = Pair.first + dx[i];
							int ny = Pair.second + dy[i];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M)
								continue;
							if (Visit[nx][ny] == 1 || Board[nx][ny] != 1)
								continue;
							Queue.push({ nx,ny });
							Visit[nx][ny] = 1;
						}
					}
				}
			}
		}

		cout << Result << "\n";
	}

	return 0;
}