#include <iostream>	
#include <vector>

using namespace std;

int N, M;
int X, Y;
//   2
// 4 1 3
//   5
//   6
// 문제에서는 주사위의 인덱스를 1 ~ 6으로 표현하지만 난 0 ~ 5로 함.
int dice[6] = {};
vector<vector<int>> board;
// 동 서 북 남. x, y가 r, c라서 주의해야 한다.
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1, -1, 0, 0 };

void Move(int dir)
{
	int nx = X + dx[dir];
	int ny = Y + dy[dir];

	// 화면 밖이면 안해
	if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		return;
	// 이동시켜
	X = nx;
	Y = ny;

	// 우선 주사위를 굴려.
	// 동. 3 0 2 5을 5 3 0 2
	if (dir == 0)
	{
		int temp[4] = { dice[5], dice[3],dice[0],dice[2] };
		dice[3] = temp[0];
		dice[0] = temp[1];
		dice[2] = temp[2];
		dice[5] = temp[3];
	}
	// 서. 3 0 2 5을 0 2 5 3
	else if (dir == 1)
	{
		int temp[4] = { dice[0], dice[2],dice[5],dice[3] };
		dice[3] = temp[0];
		dice[0] = temp[1];
		dice[2] = temp[2];
		dice[5] = temp[3];
	}
	// 북. 1, 0, 4, 5을 0, 4, 5, 1
	else if (dir == 2)
	{
		int temp[4] = { dice[0], dice[4],dice[5],dice[1] };
		dice[1] = temp[0];
		dice[0] = temp[1];
		dice[4] = temp[2];
		dice[5] = temp[3];
	}
	// 남. 1, 0, 4, 5을 5, 1, 0, 4
	else if (dir == 3)
	{
		int temp[4] = { dice[5], dice[1],dice[0],dice[4] };
		dice[1] = temp[0];
		dice[0] = temp[1];
		dice[4] = temp[2];
		dice[5] = temp[3];
	}

	// 지도랑 상호작용.
	if (board[X][Y] == 0)
	{
		board[X][Y] = dice[5];
	}
	else
	{
		dice[5] = board[X][Y];
		board[X][Y] = 0;
	}
	// 윗 면에 쓰인 수 출력
	cout << dice[0] << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int K;
	cin >> N >> M >> X >> Y >> K;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; ++i)
	{
		int dir;
		cin >> dir;
		Move(dir - 1);
	}

	return 0;
}