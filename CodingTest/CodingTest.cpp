#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	// D[i][j]: i,j 좌표를 오른쪽 아래로 하는 정사각형의 한 변의 크기.
	vector<vector<int>> D(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i)
	{
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; ++j)
		{
			board[i][j] = temp[j] - '0';
		}
	}
	
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (board[i][j])
			{
				// 좌상단, 상단, 좌측 3군데 중 최소 D 값에 + 1을 해야 정사각형을 만들 수 있다.
				D[i][j] = min({ D[i][j - 1], D[i - 1][j], D[i - 1][j - 1] }) + 1;
				result = max(result, D[i][j]);
			}
		}
	}

	cout << result * result;

	return 0;
}