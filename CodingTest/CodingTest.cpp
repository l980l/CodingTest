#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int w, h;
		cin >> w >> h;
		vector<vector<int>> Board(h, vector<int>(w));
		vector<vector<int>> Distance(h, vector<int>(w));
		queue<tuple<int, int, int>> Queue;	// r, c, fire 여부
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		int Alive = 1e9;

		// 음.. 불을 먼저 큐에 다 넣고, 상근이 위치를 그 다음에 넣으면 BFS할 때 상근이가 그냥 미리 기록된 Distance 값이 있는지만 판단해서 가면 될거 같은데? 
		int SR = 0;
		int SC = 0;
		for (int i = 0; i < h; ++i)
		{
			string S;
			cin >> S;
			for (int j = 0; j < w; ++j)
			{
				Distance[i][j] = -1;
				Board[i][j] = S[j];

				// 상근이 초기 위치는 따로 저장해두기.
				if (S[j] == '@')
				{
					SR = i;
					SC = j;
				}
				// 불의 초기 위치
				if (S[j] == '*')
				{
					Distance[i][j] = 0;
					Queue.push({ i,j,1 });
				}
			}
		}
		// 이번턴의 불의 전파 위치를 먼저 구하고, 상근이를 이동시키기 위해서 이렇게 함.
		Distance[SR][SC] = 0;
		Queue.push({ SR,SC,0 });

		while (!Queue.empty())
		{
			int r, c, fire;
			tie(r, c, fire) = Queue.front();
			Queue.pop();

			// 불의 이동
			if (fire)
			{
				for (int i = 0; i < 4; ++i)
				{
					int nx = r + dx[i];
					int ny = c + dy[i];

					if (nx < 0 || nx >= h || ny < 0 || ny >= w)
						continue;
					if (Distance[nx][ny] != -1 || Board[nx][ny]=='#')
						continue;
					Distance[nx][ny] = Distance[r][c] + 1;
					Queue.push({ nx,ny,1 });
				}
			}

			// 상근이의 이동
			else if (!fire)
			{
				for (int i = 0; i < 4; ++i)
				{
					int nx = r + dx[i];
					int ny = c + dy[i];
					// 탈출
					if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					{
						// 탈출 시간이 기록되지 않은 경우에만 기록.
						if (Alive == 1e9)
							Alive = Distance[r][c] + 1;
						continue;
					}
					if (Distance[nx][ny] != -1 || Board[nx][ny] == '#')
						continue;
					Distance[nx][ny] = Distance[r][c] + 1;
					Queue.push({ nx,ny,0 });
				}
			}
		}

		if (Alive == 1e9)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << Alive << "\n";
	}

	return 0;
}