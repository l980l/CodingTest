#include <iostream>	
#include <vector>	

using namespace std;

int N, M;
vector<string> board; // 보드 판은 그대로 있고, R과 B의 위치만 이동시킬 거임.
int ORX, ORY, OBX, OBY;
int RX, RY, BX, BY;
int Min = 2147483647;

// R 굴리기
void MoveR(int dir)
{

}
// B 굴리기
void MoveB(int dir)
{

}

// 구술이 탈출하면 true 반환. 0 1 2 3북 동 남 서
// 이동 경로 상으로 일직선상에 위치하면 앞에 있는 애가 먼저 움직이는 방식으로 처리해야 할듯? 따라서 북쪽이나 남쪽으로 이동하는 거면, R과 B가 같은 행인지 확인하고, 북쪽이면서 같은 행이면 x가 더 낮은 구슬부터, 남쪽이면 x가 더 높은 구슬부터. 동 서의 경우에는 같은 열인지 확인, 서쪽의 경우 y가 더 낮은 구슬, 동쪽의 경우 더 높은 구슬부터.
bool Tilt(int dir)
{
	// 북
	if (dir == 0)
	{
		if (ORY == OBY)
		{
			if (ORX > OBX)
			{
				MoveB(dir);
				MoveR(dir);
			}
		}
		else
		{
			MoveR(dir);
			MoveB(dir);
		}
	}
	// 동
	else if (dir == 1)
	{
		if (ORX == OBX)
		{
			if (ORY < OBY)
			{
				MoveB(dir);
				MoveR(dir);
			}
		}
		else
		{
			MoveR(dir);
			MoveB(dir);
		}
	}
	// 남
	else if (dir == 2)
	{
		if (ORY == OBY)
		{
			if (ORX < OBX)
			{
				MoveB(dir);
				MoveR(dir);
			}
		}
		else
		{
			MoveR(dir);
			MoveB(dir);
		}
	}
	// 서
	else if (dir == 3)
	{
		if (ORX == OBX)
		{
			if (ORY > OBY)
			{
				MoveB(dir);
				MoveR(dir);
			}
		}
		else
		{
			MoveR(dir);
			MoveB(dir);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	board = vector<string>(N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char c;
			// R이나 B 구슬이면 위치만 따로 저장하고, board에는 빈칸으로 만듦.
			if (c == 'R')
			{
				ORX = i;
				ORY = j;
				c = '.';
			}
			else if (c == 'B')
			{
				OBX = i;
				OBY = j;
				c = '.';
			}
			cin >> c;
			board[i].push_back(c);
		}
	}
	// 4의 10승 가지의 경우의 수를 처리. 나름 최적화는 하겠지만 연산량이 많다. 
	for (int i = 0; i < (1 << (2 * 10)); ++i)
	{
		// R, B의 초기 위치 세팅.
		RX = ORX, RY = ORY, BX = OBX, BY = OBY;
		// 이번에 기울인 횟수.
		int CurTiltCount = 0;
		int temp = i;
		// 최소로 기울이는 수를 찾는 것이기 때문에, 현재까지 찾은 최소 기울기 횟수 - 1 이하로 기울인 경우만 찾는다. 
		int TempMin = Min - 1;
		// 처음에는 10번의 기울기를 하는 경우까지 구함. 
		if (Min == 2147483647)
			TempMin = 10;
		for (int j = 0; j < TempMin; ++j)
		{
			int dir = temp % 4;
			temp /= 4;
			CurTiltCount++;
			// 기울여서 R이 나왔다면 true. 그 경우 최소값 확인후 갱신.
			if (Tilt(dir))
			{
				Min = min(Min, CurTiltCount);
				break;
			}
		}
	}

	if (Min == 2147483647)
		Min = -1;
	cout << Min;

	return 0;
}