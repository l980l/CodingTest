#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<char>> Board(N, vector<char>(N));
	vector<vector<char>> SpecialBoard(N, vector<char>(N));
	vector<vector<char>> GeneralVisit(N, vector<char>(N));
	vector<vector<char>> SpecialVisit(N, vector<char>(N));
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < N; ++j)
		{
			Board[i][j] = S[j];
			if (S[j] == 'G')
				SpecialBoard[i][j] = 'R';
			else
				SpecialBoard[i][j] = S[j];
			GeneralVisit[i][j] = 0;
			SpecialVisit[i][j] = 0;
		}
	}

	int GeneralResult = 0;		// 일반인용
	int SpecialResult = 0;		// 적록색약용

	for (char Key : {'R', 'G', 'B'})
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				// 일반인용
				if (Board[i][j] == Key && GeneralVisit[i][j] == 0)
				{
					GeneralResult++;
					queue<pair<int, int>> Queue;
					GeneralVisit[i][j] = 1;
					Queue.push({ i,j });
					while (!Queue.empty())
					{
						auto Pair = Queue.front();
						Queue.pop();

						for (int i = 0; i < 4; ++i)
						{
							int nx = Pair.first + dx[i];
							int ny = Pair.second + dy[i];

							if (nx < 0 || nx >= N || ny < 0 || ny >= N)
								continue;
							if (Board[nx][ny] != Key || GeneralVisit[nx][ny] != 0)
								continue;
							GeneralVisit[nx][ny] = 1;
							Queue.push({ nx,ny });
						}
					}
				}

				// 적록색약용
				if (SpecialBoard[i][j] == Key && SpecialVisit[i][j] == 0)
				{
					SpecialResult++;
					queue<pair<int, int>> Queue;
					SpecialVisit[i][j] = 1;
					Queue.push({ i,j });
					while (!Queue.empty())
					{
						auto Pair = Queue.front();
						Queue.pop();

						for (int i = 0; i < 4; ++i)
						{
							int nx = Pair.first + dx[i];
							int ny = Pair.second + dy[i];

							if (nx < 0 || nx >= N || ny < 0 || ny >= N)
								continue;
							if (SpecialBoard[nx][ny] != Key || SpecialVisit[nx][ny] != 0)
								continue;
							SpecialVisit[nx][ny] = 1;
							Queue.push({ nx,ny });
						}
					}
				}
			}
		}
	}

	cout << GeneralResult << " " << SpecialResult;

	return 0;
}