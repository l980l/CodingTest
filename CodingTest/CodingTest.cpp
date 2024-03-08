#include <iostream>
#include <vector>

using namespace std;

int N;
int Max;
vector<vector<int>> board;
vector<vector<int>> copyboard;

// 상 우 하 좌
void Move(int dir)
{
	// 상
	if (dir == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			// 우선 임시 벡터에 0이 아닌 수만 집어넣음. 이때 이동 방향에 따라 넣는 순서가 달라짐.
			vector<int> temp;
			for (int j = 0; j < N; ++j)
			{
				if (copyboard[j][i] != 0)
					temp.push_back(copyboard[j][i]);
			}
			// 임시 벡터 temp를 반복 돌면서, 같은 수가 연속으로 나오면 뒷 수를 지우고, 앞 수를 2배로 만듦.
			auto iter = temp.begin();
			for (; iter != temp.end(); )
			{
				if (iter + 1 == temp.end())
					break;
				if (*iter == *(iter + 1))
				{
					*iter *= 2;
					iter = temp.erase(iter + 1);
				}
				else
					++iter;
			}
			// 임시 벡터에 저장된 수를 다시 채워넣음. 
			int size = (int)temp.size();
			for (int j = 0; j < size; ++j)
			{
				copyboard[j][i] = temp[j];
			}
			// 임시 벡터가 끝나면 남은 부분은 0으로 넣으면 됨.
			for (int j = size; j < N; ++j)
			{
				copyboard[j][i] = 0;
			}
		}
	}
	// 하
	else if (dir == 1)
	{
		for (int i = 0; i < N; ++i)
		{
			vector<int> temp;
			for (int j = 0; j < N; ++j)
			{
				if (copyboard[N - 1 - j][i] != 0)
					temp.push_back(copyboard[N - 1 - j][i]);
			}
			auto iter = temp.begin();
			for (; iter != temp.end(); )
			{
				if (iter + 1 == temp.end())
					break;
				if (*iter == *(iter + 1))
				{
					*iter *= 2;
					iter = temp.erase(iter + 1);
				}
				else
					++iter;
			}
			int size = (int)temp.size();
			for (int j = 0; j < size; ++j)
			{
				copyboard[N - 1 - j][i] = temp[j];
			}
			for (int j = size; j < N; ++j)
			{
				copyboard[N - 1 - j][i] = 0;
			}
		}
	}
	// 좌
	else if (dir == 2)
	{
		for (int i = 0; i < N; ++i)
		{
			vector<int> temp;
			for (int j = 0; j < N; ++j)
			{
				if (copyboard[i][j] != 0)
					temp.push_back(copyboard[i][j]);
			}
			auto iter = temp.begin();
			for (; iter != temp.end(); )
			{
				if (iter + 1 == temp.end())
					break;
				if (*iter == *(iter + 1))
				{
					*iter *= 2;
					iter = temp.erase(iter + 1);
				}
				else
					++iter;
			}
			int size = (int)temp.size();
			for (int j = 0; j < size; ++j)
			{
				copyboard[i][j] = temp[j];
			}
			for (int j = size; j < N; ++j)
			{
				copyboard[i][j] = 0;
			}
		}
	}
	// 우
	else if (dir == 3)
	{
		for (int i = 0; i < N; ++i)
		{
			vector<int> temp;
			for (int j = 0; j < N; ++j)
			{
				if (copyboard[i][N - 1 - j] != 0)
					temp.push_back(copyboard[i][N - 1 - j]);
			}
			auto iter = temp.begin();
			for (; iter != temp.end(); )
			{
				if (iter + 1 == temp.end())
					break;
				if (*iter == *(iter + 1))
				{
					*iter *= 2;
					iter = temp.erase(iter + 1);
				}
				else
					++iter;
			}
			int size = (int)temp.size();
			for (int j = 0; j < size; ++j)
			{
				copyboard[i][N - 1 - j] = temp[j];
			}
			for (int j = size; j < N; ++j)
			{
				copyboard[i][N - 1 - j] = 0;
			}
		}
	}
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
			Move(dir);
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