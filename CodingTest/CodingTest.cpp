#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> board;
vector<int> team;
int Min = 2147483647;

void func()
{
	vector<vector<int>> TeamBoard(N, vector<int>(N));

	for (int i =0;i<N;++i)
	{
		// 0 팀이면 본인의 행과 열에 -1
		if (team[i] == 0)
		{
			int j = 0;
			while (j < N)
			{
				TeamBoard[i][j] -= 1;
				TeamBoard[j][i] -= 1;
				j++;
			}
		}
		// 1 팀이면 본인의 행과 열에 +1
		else if (team[i] == 1)
		{
			int j = 0;
			while (j < N)
			{
				TeamBoard[i][j] += 1;
				TeamBoard[j][i] += 1;
				j++;
			}
		}
	}

	int T0 = 0;
	int T1 = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 0번 팀인거임.
			if (TeamBoard[i][j] == -2)
			{
				T0 += board[i][j];
			}
			// 1번 팀인거임.
			else if (TeamBoard[i][j] == 2)
			{
				T1 += board[i][j];
			}
		}
	}

	Min = min(abs(T0 - T1), Min);
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

	team = vector<int>(N);
	fill(team.begin() + N / 2, team.begin() + N, 1);
	do
	{
		func();
	} while (next_permutation(team.begin(), team.end()));

	cout << Min;

	return 0;
}