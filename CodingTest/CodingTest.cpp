#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> board;
vector<vector<bool>> visit;
vector<pair<int, int>> adjPY;
queue<pair<int, int>> Q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };
int adj = 0;
bool NowChain;
int TotalChain = 0;

// 밑으로 떨어뜨리기.
void Gravity()
{
	for (int i = 0; i < 6; ++i)
	{
		string temp;
		for (int j = 0; j < 12; ++j)
		{
			if (board[12 - 1 - j][i] == '.')
				continue;
			temp.push_back(board[12 - 1 - j][i]);
			// 일단은 '.'으로 채워두기. 지금보니 temp를 '.' 12개로 채워뒀어도 되겠네.
			board[12 - 1 - j][i] = '.';
		}
		// 뿌요 넣기
		int size = (int)temp.size();
		for (int j = 0; j < size; ++j)
		{
			if (temp[j] == '.')
				continue;
			board[12 - 1 - j][i] = temp[j];
		}
	}
}

// 같은 색의 뿌요가 인접해 있는 경우 adjPY 백터에 주소를 저장해두는 함수.
void BFS()
{
	while (!Q.empty())
	{
		auto pair = Q.front();
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pair.first + dx[i];
			int ny = pair.second + dy[i];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6 || visit[nx][ny])
				continue;
			if (board[pair.first][pair.second] == board[nx][ny])
			{
				visit[nx][ny] = true;
				Q.push(make_pair(nx, ny));
				adjPY.push_back(make_pair(nx, ny));
				adj++;
			}
		}
	}
}

// 연쇄 되는 뿌요가 있는지 확인하는 함수. 
void Func()
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (board[i][j] == '.')
				continue;
			if (!visit[i][j])
			{
				visit[i][j] = true;
				Q.push(make_pair(i, j));
				adjPY.push_back(make_pair(i, j));
				adj = 1;
				// i, j와 인접한 같은 색상의 뿌요 adjPY에 저장하기.
				BFS();
				// 인접 뿌요가 4개 이상이면 연쇄.
				if (adj >= 4)
				{
					NowChain = true;
					for (auto pair : adjPY)
					{
						board[pair.first][pair.second] = '.';
					}
				}
				adjPY.clear();
			}
		}
	}
}

int main()
{
	visit = vector<vector<bool>>(12, vector<bool>(6, false));
	for (int i = 0; i < 12; ++i)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	while(true)
	{
		NowChain = false;
		Func();
		// 이번에 연쇄 안생겼으면 break;
		if (NowChain == false)
			break;
		TotalChain += NowChain;
		// 밑으로 밀기.
		Gravity();
		visit = vector<vector<bool>>(12, vector<bool>(6, false));
	} 

	cout << TotalChain;

	return 0;
}