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
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int a;
			cin >> a;
			Board[i][j] = a;
		}
	}

	// 얼음 덩어리 개수. 초기에는 1개로 주어진다. 
	int Mass = 1;
	int Year = 0;
	// 덩어리가 0이 되면 0출력 2 이상이 되면 그때의 시간 출력.
	while (Mass == 1)
	{
		Mass = 0; 
		Year++;
		// 매년 새롭게 NearIce 배열 만들기.
		vector<vector<int>> NearIce(N, vector<int>(M));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				// 0이 아닌 곳이 비방문 상태라면
				if (Board[i][j] != 0 && !NearIce[i][j])
				{
					// 덩어리 ++
					Mass++;
					queue<pair<int, int>> Queue;
					Queue.push({ i,j });
					NearIce[i][j] = true;
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
							// 바다인 경우 -1
							if (Board[nx][ny] == 0)
							{
								// Board[Pair.first][Pair.second] -= 1; 이렇게하면 Board가 실시간으로 변경돼서 원하지 않는 결과가 나올듯.
								NearIce[Pair.first][Pair.second]++;	// NearIce에 ++을 해서 처리해주자.
							}
							// 얼음인데 방문한적 없는 경우
							else if(NearIce[nx][ny] == 0)
							{
								Queue.push({ nx,ny });
								NearIce[nx][ny] = 1;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				// 얼음인 경우
				if (Board[i][j] != 0)
				{
					// 방문할 때 NearIce를 1을 넣어주기 때문에 1을 덜 빼야 된다. 
					Board[i][j] = Board[i][j] - NearIce[i][j] + 1;
					// 0 이하로는 못가게 하기.
					if (Board[i][j] < 0)
						Board[i][j] = 0;
				}
			}
		}
	}

	if (Mass == 0)
		cout << 0;
	else
		cout << Year - 1;

	return 0;
}