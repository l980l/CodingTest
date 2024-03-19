#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
vector<vector<int>> board;
int Result;

bool func(vector<int>& Line)
{
	int idx = 0;
	int cnt = 1; 
	while (idx < N - 1)
	{
		if (abs(Line[idx + 1] - Line[idx]) > 1)
			return 0;
		if (Line[idx] == Line[idx + 1])
		{
			cnt++;
			idx++;
		}
		// 다음 높이가 더 높을 때
		else if (Line[idx] < Line[idx + 1])
		{
			if (cnt < L)
				return 0;
			cnt = 1;
			idx++;
		}
		// 다음 높이가 더 낮을 때
		else
		{
			if (idx + L >= N)
				return 0;
			for (int i = idx + 1; i < idx + L; ++i)
			{
				if (Line[i] != Line[i + 1])
					return 0;
				idx = idx + L;
				cnt = 0;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	board = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 행
	for (int i = 0; i < N; ++i)
	{
		vector<int> Line;
		for (int j = 0; j < N; ++j)
		{
			Line.push_back(board[i][j]);
			Result += func(Line);
		}
	}

	// 열
	for (int i = 0; i < N; ++i)
	{
		vector<int> Line;
		for (int j = 0; j < N; ++j)
		{
			Line.push_back(board[j][i]);
			Result += func(Line);
		}
	}

	cout << Result;

	return 0;
}