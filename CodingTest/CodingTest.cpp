#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	queue<tuple<int, int, int>> Queue;	// 3번인자: 0이면 바다, 1이면 섬
	vector<vector<int>> Board(N, vector<int>(N));
	vector<vector<int>> Visit(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int a;
			cin >> a;
			Board[i][j] = a;
		}
	}

	// 음... 섬에 따라 번호를 다르게 넣게 하자. 
	int Island = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 방문하지 않은 섬인 경우
			if (Visit[i][j] == 0 && Board[i][j] == 1)
			{
				Visit[i][j] = 1;
				Queue.push({ i,j,1 });
				Board[i][j] = Island;

				while (!Queue.empty())
				{
					int x, y, z;
					tie(x, y, z) = Queue.front();
					Queue.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if (Board[nx][ny] != 1 || Visit[nx][ny] == 1)
							continue;
						Board[nx][ny] = Island;
						Visit[nx][ny] = 1;
						Queue.push({ nx , ny, 1 });
					}
				}
				// 다음 섬의 번호 ++
				Island++;
			}
		}
	}

	// Visit는 다시 0로 초기화
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Visit[i][j] = 0;
		}
	}

	// 이번에는 섬들 간의 거리를 구하자.
	// 이번에는 Island 변수를 출발 섬 번호로 사용할 것이다.
	Island = 0;
	int Result = 1e9;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Visit[i][j] == 0 && Board[i][j] > 0)
			{
				Queue.push({ i,j, 1 });
				Visit[i][j] = 1;
				Island = Board[i][j];
				// 섬마다 다른 거리 배열이 필요
				vector<vector<int>> Distance(N, vector<int>(N));

				while (!Queue.empty())
				{
					int x, y, z;
					tie(x, y, z) = Queue.front();
					Queue.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						// 이전 위치가 바다인 경우 섬을 만나야 함.
						if (z == 0)
						{
							// 바다인데 Distance가 0인것은 방문하지 않은 것임.
							if (Board[nx][ny] == 0 && Distance[nx][ny] == 0)
							{
								Distance[nx][ny] = Distance[x][y] + 1;
								Queue.push({ nx,ny,0 });
							}
							// 다리 가능
							else if (Board[nx][ny] != Island && Board[nx][ny] != 0)
							{
								Result = min(Result, Distance[x][y]);
								while (!Queue.empty())
									Queue.pop();
								break;
							}
						}

						// 이전 위치가 섬인 경우
						else if (z == 1)
						{
							// 같은 섬이면 Visit을 검사
							if (Board[nx][ny] == Island && Visit[nx][ny] == 0)
							{
								Visit[nx][ny] = 1;
								Queue.push({ nx,ny,1 });
							}
							// 바다면 이제부터 거리 + 1
							else if (Board[nx][ny] == 0 && Distance[nx][ny] == 0)
							{
								Distance[nx][ny] = Distance[x][y] + 1;
								Queue.push({ nx,ny,0 });
							}
						}
					}
				}
			}
		}
	}

	cout << Result;

	return 0;
}