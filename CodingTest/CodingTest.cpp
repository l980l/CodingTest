#include <iostream>	
#include <vector>	

using namespace std;

int N, M;
int r, c, d;	// 문제에서 d는 0 북 1 동 2 남 3 서 이지만 북,서,남,동으로 사용할거임.
vector<vector<int>> board;
vector<vector<bool>> cleaned;
int result = 0;
// 회전을 반시계방향으로 90도씩 시키기 때문에 북,서,남,동을 가리키도록 만듦.
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> r >> c >> d;
	// 편의를 위해 d를 북 서 남 동으로 사용할 것이기 때문에 
	if (d == 1)
		d = 3;
	else if (d == 3)
		d = 1;
	board = vector<vector<int>>(N, vector<int>(M));
	cleaned = vector<vector<bool>>(N, vector<bool>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	result++;
	cleaned[r][c] = true;
	while (true)
	{
		int FD;
		bool cleaning = false;
		// 무조건 회전을 먼저 하는거였네;; 이 조건 못찾아서 1시간 이상 날림;;
		for (int i = 1; i <= 4; ++i)
		{
			FD = (d + i) % 4;
			int nx = r + dx[FD];
			int ny = c + dy[FD];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 1 || cleaned[nx][ny] == true)
				continue;
			r = nx;
			c = ny;
			d = FD;
			cleaned[nx][ny] = true;
			result++;
			cleaning = true;
			break;
		}
		// 청소 성공 했으면 다음 구역으로.
		if (cleaning)
			continue;
		// 역방향
		FD = (d + 2) % 4;
		int nx = r + dx[FD];
		int ny = c + dy[FD];
		// 청소 종료
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 1)
			break;
		// 청소는 못하고 뒤로 가는 경우. d는 그대로 유지해야 한다. 
		r = nx;
		c = ny;
	}

	cout << result;

	return 0;
}