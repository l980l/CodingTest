#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int G, R;
	int max = 0;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	cin >> N >> M >> G >> R;

	// 0 호수, 1 배양액 뿌릴 수 없는 땅, 2 배양액 뿌릴 수 있는 땅
	vector<vector<int>> board = vector<vector<int>>(N, vector<int>(M));
	// 배양액을 뿌릴 수 있는 땅 주소.
	vector<pair<int, int>> InitRGBoard;
	// BFS를 위한 큐
	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				InitRGBoard.push_back(make_pair(i,j));
			}
		}
	}

	vector<int> InitRGIdx(InitRGBoard.size(), 2);	// 초기 배양액 위치를 만들기 위한 배열. 0은 초기 G, 1은 초기 R, 2는 Default
	fill(InitRGIdx.begin(), InitRGIdx.begin() + G, 0);	// 초기 G 주소
	fill(InitRGIdx.begin() + G, InitRGIdx.begin() + G + R, 1);	// 초기 R 주소

	do
	{
		vector<vector<int>> copyboard = board;		// 0 호수, 1 배양액 뿌릴 수 없는 땅, 2 배양액 뿌릴 수 있는 땅, 3 G, 4 R, 5 Flower
		vector<vector<int>> distance(N, vector<int>(M, -1));	// 초기 배양액으로부터의 거리
		int cnt = 0;	// 이번에 피운 꽃의 수

		for (int i = 0; i < InitRGIdx.size(); ++i)
		{
			// 초기 G
			if (InitRGIdx[i] == 0)
			{
				auto pair = InitRGBoard[i];
				copyboard[pair.first][pair.second] = 3;
				distance[pair.first][pair.second] = 0;
				q.push(make_pair(pair.first, pair.second));
			}
			// 초기 R
			if (InitRGIdx[i] == 1)
			{
				auto pair = InitRGBoard[i];
				copyboard[pair.first][pair.second] = 4;
				distance[pair.first][pair.second] = 0;
				q.push(make_pair(pair.first, pair.second));
			}
		}
		// BFS 
		while (!q.empty())
		{
			auto pair = q.front();
			q.pop();

			// 꽃이 핀 경우 그만.
			if (copyboard[pair.first][pair.second] == 5)
				continue;

			for (int k = 0; k < 4; ++k)
			{
				int nx = pair.first + dx[k];
				int ny = pair.second + dy[k];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				// 호수거나 꽃이거나
				if (copyboard[nx][ny] == 0 || copyboard[nx][ny] == 5)
					continue;
				// 초록땅인 경우
				if (copyboard[nx][ny] == 3)
				{
					// 이번에 넣을 배양액이 R이어야 함. 또한 이미 설정된 거리와 R에서의 거리가 같아야 함.
					if (copyboard[pair.first][pair.second] == 4 && distance[nx][ny] == distance[pair.first][pair.second] + 1)
					{
						copyboard[nx][ny] = 5;
						cnt++;
					}
				}
				// 빨간땅인 경우
				else if (copyboard[nx][ny] == 4)
				{
					// 이번에 넣을 배양액이 G이어야 함. 또한 이미 설정된 거리와 R에서의 거리가 같아야 함.
					if (copyboard[pair.first][pair.second] == 3 && distance[nx][ny] == distance[pair.first][pair.second] + 1)
					{
						copyboard[nx][ny] = 5;
						cnt++;
					}
				}
				// 아직 배양되지 않은 땅.
				else
				{
					copyboard[nx][ny] = copyboard[pair.first][pair.second];
					distance[nx][ny] = distance[pair.first][pair.second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}

		if (max < cnt)
			max = cnt;
	} while (next_permutation(InitRGIdx.begin(), InitRGIdx.end())); // 배열은 끝 주소를 2번인자로 넣는데, end()는 끝 주소 다음 주소를 반환하니까 -1 해야하지 않을까? 싶었지만 아니네~ 생각해보니 배열을 넣을 때도, 배열 끝주소 + 1을 넣는구나 ㅎㅎ "시작 주소 + 배열 길이" 이런 식으로 넣으니까.

	cout << max;

	return 0;
}