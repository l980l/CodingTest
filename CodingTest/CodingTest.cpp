#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, L;
vector<vector<int>> board;	// 사과가 있으면 1, 없으면 0, 뱀이 있으면 2
int X = 0, Y = 0;
int Sec = 0;
queue<pair<int, char>> Moving;
int Dir = 1; // 0 북 1 동 2 남 3 서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Snake;	// 뱀 위치.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	board = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < K; ++i)
	{
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; ++i)
	{
		int x;
		char c;
		cin >> x >> c;
		Moving.push(make_pair(x, c));
	}

	board[X][Y] = 2;
	Snake.push(make_pair(X, Y));
	auto pair = Moving.front();
	while (true)
	{
		// 이동
		X += dx[Dir];
		Y += dy[Dir];
		// Sec 늘리기                                                                       
		Sec++;
		// 종료
		if (X < 0 || X >= N || Y < 0 || Y >= N || board[X][Y] == 2)
			break;
		
		// 사과가 아니야. 그럼 꼬리를 잘라.
		if (board[X][Y] == 0)
		{                                                                                               
			auto Tail = Snake.front();
			Snake.pop();
			board[Tail.first][Tail.second] = 0;
		}
		// 뱀으로 추가.
		board[X][Y] = 2;
		Snake.push(make_pair(X, Y));

		// 방향 바꾸기.
		if (Sec == pair.first)
		{
			// 오른쪽으로 90도 회전
			if (pair.second == 'D')
			{
				Dir = (Dir + 1) % 4;
			}
			// 왼쪽으로 90도 회전
			else
			{
				// 4를 더한 다음 -1을 해서 음수가 나오지 않도록 처리
				Dir = (Dir + 4 - 1) % 4;
			}
			Moving.pop();
			if (!Moving.empty())
			{
				pair = Moving.front();
			}
		}
	}

	cout << Sec;

	return 0;
}