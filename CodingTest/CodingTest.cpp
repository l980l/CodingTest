#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int origincube[5][5][5] = {};
int suffledcube[5][5][5] = {};
int copycube[5][5][5] = {};
int dis[5][5][5] = {};
int dz[6] = { 0, 0,0, 0,1,-1, };
int dx[6] = { 1,0,-1,0, 0, 0 };
int dy[6] = { 0,1,0,-1, 0, 0 };
int Min = 2147483647;

void Shuffle(int* Order)
{
	for (int h = 0; h < 5; ++h)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				suffledcube[h][i][j] = origincube[Order[h]][i][j];
			}
		}
	}
}

// cube 복사 및 dis 배열 초기화
void Copy()
{
	for (int h = 0; h < 5; ++h)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				copycube[h][i][j] = suffledcube[h][i][j];
				dis[h][i][j] = -1;
			}
		}
	}
}

// 층 하나를 시계방향으로 회전시키는 함수.
void Rotate(int level)
{
	int temp[5][5];
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			temp[i][j] = copycube[level][5 - 1 - j][i];
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			swap(temp[i][j], copycube[level][i][j]);
		}
	}
}

// 0, 0, 0에서 4, 4, 4로 이동하는 함수.
bool Move()
{
	// 첫 위치나 끝이 막힌 경우 -1 
	if (copycube[0][0][0] == 0 || copycube[4][4][4] == 0)
		return false;
	// BFS 해야함
	queue<tuple<int, int, int>> Q;
	Q.push(make_tuple(0, 0, 0));
	dis[0][0][0] = 0;
	while (!Q.empty())
	{
		int h, x, y;
		tie(h, x, y) = Q.front();
		Q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int nh = h + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nh < 0 || nh >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || copycube[nh][nx][ny] == 0 || dis[nh][nx][ny] != -1)
				continue;
			dis[nh][nx][ny] = dis[h][x][y] + 1;
			// 종점 도달.
			if (nh == 4 && nx == 4 && ny == 4)
				return true;
			Q.push(make_tuple(nh, nx, ny));
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int h = 0; h < 5; ++h)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cin >> origincube[h][i][j];
			}
		}
	}
	
	int Order[5] = { 0,1,2,3,4 };
	do
	{
		Shuffle(Order);
		for (int i = 0; i < (1 << (2 * 5)); ++i)
		{
			Copy();
			int temp = i;
			for (int j = 0; j < 5; ++j)
			{
				int rep = temp % 4;
				temp /= 4;
				for (int r = 0; r < rep; ++r)
				{
					Rotate(j);
				}
			}
			// 길찾기 및 최단경로
			if (Move())
				Min = min(Min, dis[4][4][4]);
		}
	} while (next_permutation(Order, Order + 5));

	if (Min == 2147483647)
		Min = -1;
	cout << Min;

	return 0;
}