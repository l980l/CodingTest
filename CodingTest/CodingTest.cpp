#include <iostream>	
#include <vector>	

using namespace std;

int N, M;
int Min;
vector<vector<int>> originboard;
vector<vector<int>> copyboard;
vector<pair<int,int>> cctv;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void look(int x, int y, int dir)
{
	dir %= 4;

	while (true)
	{
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M)
			break;
		if (copyboard[x][y] == 6)
			break;
		if (copyboard[x][y] == 0)
			copyboard[x][y] = '#';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	originboard = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> originboard[i][j];
			// cctv인 경우
			if (originboard[i][j] != 6 && originboard[i][j] != 0)
				cctv.push_back(make_pair(i, j));
			// 사각지대
			if (originboard[i][j] == 0)
				Min++;
		}
	}

	// cctv 개수. cctv 각각의 방향을 0~4까지의 숫자로 나타내어 모든 경우의 수를 체크할 것이다. 
	int cctvcount = cctv.size();
	int maxdir = 1;
	for (int i = 0; i < cctvcount; ++i)
	{
		maxdir *= 4;
	}

	// 만들 수 있는 경우의 수가 maxdir임. pow는 안쓰는게 안전하고, 비트쉬프트 연산자를 사용해서 1 << 2 * cctvcount를 maxdir로 사용해도 됨.
	for (int i = 0; i <= maxdir; ++i)
	{
		// 카피보드 초기화
		copyboard = originboard;
		int temp = i;
		// 각 cctv의 방향을 정하기 위해 1자리씩 잘라서 사용
		for (int j = 0; j < cctvcount; ++j)
		{
			// 4진수로 temp를 사용하기 위해 4로 나눈 나머지를 사용한다. 
			int dir = temp % 4;
			if (originboard[cctv[j].first][cctv[j].second] == 1)
			{
				look(cctv[j].first, cctv[j].second, dir);
			}
			else if (originboard[cctv[j].first][cctv[j].second] == 2)
			{
				look(cctv[j].first, cctv[j].second, dir);
				look(cctv[j].first, cctv[j].second, dir +2);
			}
			else if (originboard[cctv[j].first][cctv[j].second] == 3)
			{
				look(cctv[j].first, cctv[j].second, dir);
				look(cctv[j].first, cctv[j].second, dir + 1);
			}
			else if (originboard[cctv[j].first][cctv[j].second] == 4)
			{
				look(cctv[j].first, cctv[j].second, dir);
				look(cctv[j].first, cctv[j].second, dir + 1);
				look(cctv[j].first, cctv[j].second, dir + 2);
			}
			else if (originboard[cctv[j].first][cctv[j].second] == 5)
			{
				look(cctv[j].first, cctv[j].second, dir);
				look(cctv[j].first, cctv[j].second, dir + 1);
				look(cctv[j].first, cctv[j].second, dir + 2);
				look(cctv[j].first, cctv[j].second, dir + 3);
			}

			temp /= 4;
		}

		int tempmin = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (copyboard[i][j] == 0)
					tempmin++;
			}
		}
		// Min과 tempmin 중 작은 값으로 Min 설정.
		Min = min(Min, tempmin);
	}

	cout << Min;

	return 0;
}