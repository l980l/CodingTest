#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

// 말 이동
int hdx[8] = { -2,-1,1,2,-2,-1,1,2 };
int hdy[8] = { 1,2,2,1,-1,-2,-2,-1 };
// 원숭이 이동
int mdx[4] = { 0,0,1,-1 };
int mdy[4] = { 1,-1,0,0 };

int K, W, H;

vector<vector<int>> Board;
vector<vector<vector<int>>> Distance;
queue<tuple<int, int, int>> Queue;	// 3번째 요소는 남은 K 수임.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> K >> W >> H;
	Board = vector<vector<int>>(H, vector<int>(W));
	Distance = vector<vector<vector<int>>>(31, vector<vector<int>>(H, vector<int>(W)));

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> Board[i][j];
			for (int w = 0; w < 31; ++w)
			{
				Distance[w][i][j] = -1;
			}
		}
	}

	Distance[0][0][0] = 0;
	Queue.push({ 0, 0, K });
	while (!Queue.empty())
	{
		int r, c, k;
		tie(r, c, k) = Queue.front();
		Queue.pop();

		// 말로 이동할 때
		if (k)
		{
			for (int i = 0; i < 8; ++i)
			{
				int nx = r + hdx[i];
				int ny = c + hdy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W)
					continue;
				if (Board[nx][ny] == 1 || Distance[K - k + 1][nx][ny] != -1)
					continue;
				Distance[K - k + 1][nx][ny] = Distance[K - k][r][c] + 1;
				Queue.push({ nx,ny, k - 1 });
			}
		}
		// 원숭이로 이동할 때
		for (int i = 0; i < 4; ++i)
		{
			int nx = r + mdx[i];
			int ny = c + mdy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W)
				continue;
			if (Board[nx][ny] == 1 || Distance[K - k][nx][ny] != -1)
				continue;
			Distance[K-k][nx][ny] = Distance[K - k][r][c] + 1;
			Queue.push({ nx,ny, k });
		}
	}
	// 결과 도출
	int  Result = -1;
	for (int i = 0; i < 31; ++i)
	{
		if (Distance[i][H - 1][W - 1] != -1)
		{
			if (Result == -1)
				Result = Distance[i][H - 1][W - 1];
			Result = min(Result, Distance[i][H - 1][W - 1]);
		}
	}

	cout << Result;

	return 0;
}
