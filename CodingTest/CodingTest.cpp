#include <iostream>	
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
vector<vector<bool>> board;
queue<vector<vector<bool>>> stickers;

// 0번 스티커 Turn 시키기.
void TurnSticker(vector<vector<bool>>& sticker)
{
	int SizeX = sticker.size();	// 열 길이
	int SizeY = sticker.front().size();	// 어차피 직사각형이라 모든 행의 길이가 같음. 
	// 새로운 스티커
	vector<vector<bool>> NewSticker;
	for (int i = 0; i < SizeY; ++i)
	{
		vector<bool> temp1;
		for (int j = SizeX -1; j >= 0; --j)
		{
			temp1.push_back(sticker[j][i]);
		}
		NewSticker.push_back(temp1);
	}
	// 새로 만든 스티커로 바꾸기
	sticker = NewSticker;
}

// 스티커의 LeftTop 좌표 값. 
bool Stick(int x, int y, const vector<vector<bool>>& sticker)
{
	int SizeX = sticker.size();	// 열 길이
	int SizeY = sticker.front().size();	// 어차피 직사각형이라 모든 행의 길이가 같음. 
	for (int i = 0; i < SizeX; ++i)
	{
		for (int j = 0; j < SizeY; ++j)
		{
			int nx = x + i;
			int ny = y + j;
			// 노트북 넘어감. 
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				return false;
			// 붙일 수 없음.
			if (board[nx][ny] == 1 && sticker[i][j] == 1)
				return false;
		}
	}
	// 붙일 수 있는 경우
	for (int i = 0; i < SizeX; ++i)
	{
		for (int j = 0; j < SizeY; ++j)
		{
			if (board[x + i][y + j] == 0 && sticker[i][j] == 1)
				board[x + i][y + j] = 1;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	board = vector<vector<bool>>(N, vector<bool>(M));

	for (int i = 0; i < K; ++i)
	{
		int x, y;
		cin >> x >> y;
		vector<vector<bool>> temp1;
		for (int c = 0; c < x; ++c)
		{
			vector<bool> temp2;
			for (int r = 0; r < y; ++r)
			{
				bool input;
				cin >> input;
				temp2.push_back(input);
			}
			temp1.push_back(temp2);
		}
		stickers.push(temp1);
	}

	while (!stickers.empty())
	{
		vector<vector<bool>> sticker = stickers.front();
		stickers.pop();
		bool isSticked = false;
		int TurnCount = 0;

		// 붙였거나, 4번 회전시켰거나.
		while (!isSticked && TurnCount < 4)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < M; ++j)
				{
					// 스티커의 크기를 고려해서 LT의 위치로 가능한 위치를 확인해본다.
					if (Stick(i, j, sticker))
					{
						// 스티커 붙이기 성공.
						isSticked = true;
						break;
					}
				}
				if (isSticked)
					break;
			}
			if (isSticked)
				break;
			// 회전시키기.
			TurnSticker(sticker);
			TurnCount++;
		}
	}

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 1)
				result++;
		}
	}
	cout << result;

	return 0; 
}