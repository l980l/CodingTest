#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int Max;
vector<vector<int>> board;
vector<vector<int>> copyboard;

void Move(int dir)
{

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	board = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 5번의 swipe 중 나올 수 있는 방향의 가지 수는 4의 5승이다.
	for (int i = 0; i < (1 << 2 * 5); ++i)
	{
		copyboard = board;
		int temp = i;
		for (int j = 0; j < 5; ++j)
		{
			int dir = temp % 4;
			temp /= 4;
			if (dir == 0)
			{

			}

			else if (dir == 1)
			{

			}

			else if (dir == 2)
			{

			}

			else if (dir == 3)
			{

			}
		}
		for (int h = 0; h < N; ++h)
		{
			for (int w = 0; w < N; ++w)
			{
				Max = max(Max, copyboard[h][w]);
			}
		}
	}
	cout << Max;

	return 0;
}