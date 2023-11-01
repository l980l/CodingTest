#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int PaintCount = 0;
	int max = 0;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	vector<vector<int>> Board(n, vector<int>(m));
	vector<vector<bool>> Visit(n, vector<bool>(m));
	queue<pair<int, int>> Queue;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a;
			cin >> a;
			Board[i][j] = a;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!Visit[i][j] && Board[i][j])
			{
				// 그림 개수 늘리기.
				PaintCount++;

				Visit[i][j] = true;
				Queue.push({ i,j });

				int temp = 1;

				while (!Queue.empty())
				{
					pair<int, int> Pair = Queue.front();
					Queue.pop();

					for (int i = 0; i < 4; ++i)
					{
						if (Pair.first + dx[i] < 0 || Pair.first + dx[i] >= n || Pair.second + dy[i] < 0 || Pair.second + dy[i] >= m)
							continue;

						else if (Board[Pair.first + dx[i]][Pair.second + dy[i]] && !Visit[Pair.first + dx[i]][Pair.second + dy[i]])
						{
							Queue.push({ Pair.first + dx[i], Pair.second + dy[i] });
							Visit[Pair.first + dx[i]][Pair.second + dy[i]] = true;
							temp++;
						}
					}
				}

				if (max < temp)
					max = temp;
			}
		}
	}

	cout << PaintCount << "\n";
	cout << max << "\n";

	return 0;
}