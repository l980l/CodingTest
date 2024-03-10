#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Gear(4);	// 각 기어 배열
vector<int> TopIdx(4);			// 각 기어의 12시 인덱스

// 지금 Rotate 함수를 호출하게 만든 Gear를 prevG로 받음. 같은 경우에는 prevG가 없는 것.
void Rotate(int GIdx, int dir, int prevG)
{
	bool LeftRot = false;
	bool RightRot = false;

	// 왼쪽 기어 검사
	if (GIdx <= 3 && GIdx > 0 && GIdx <= prevG)
	{
		int Top1 = TopIdx[GIdx - 1] + 2;
		int Top2 = TopIdx[GIdx] + 6;
		if (Top1 > 7)
			Top1 -= 8;
		if (Top2 > 7)
			Top2 -= 8;

		if (Gear[GIdx - 1][Top1] != Gear[GIdx][Top2])
			LeftRot = true;
	}

	// 오른쪽 기어 검사
	if (GIdx >= 0 && GIdx < 3 && GIdx >= prevG)
	{
		int Top1 = TopIdx[GIdx] + 2;
		int Top2 = TopIdx[GIdx + 1] + 6;
		if (Top1 > 7)
			Top1 -= 8;
		if (Top2 > 7)
			Top2 -= 8;

		if (Gear[GIdx][Top1] != Gear[GIdx + 1][Top2])
			RightRot = true;
	}

	TopIdx[GIdx] += dir;
	// Top 인덱스가 음수면 8을 더해서 양수로 만들어 주기.
	if (TopIdx[GIdx] < 0)
		TopIdx[GIdx] += 8;
	if (TopIdx[GIdx] > 7)
		TopIdx[GIdx] -= 8;

	// 이렇게 따로 LeftRot, RightRot을 만들어서 호출하는 이유는 TopIdx[GIdx]을 변경하기 전에 양 옆 기어의 회전 여부를 구해둬야 하기 때문이다.
	if (LeftRot)
		Rotate(GIdx - 1, dir * -1, GIdx);
	if (RightRot)
		Rotate(GIdx + 1, dir * -1, GIdx);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; ++i)
	{
		string temp;
		cin >> temp;
		for (char c : temp)
		{
			Gear[i].push_back(c - '0');
		}
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		// 톱니 번호, 회전 방향(1이 시계방향, -1이 반시계방향)
		int x, y;
		cin >> x >> y;
		// 나는 기어번호를 0~3으로 쓰고 문제는 1부터 4로 써서 -1을 해줌.
		// 1이 시계방향이고 -1이 반시계방향이라 반대로 넣어주려고 -1을 곱함.
		Rotate(x - 1, -y, x - 1);
	}

	int Result = 0;
	for (int i = 0; i < 4; ++i)
	{
		// 비트 쉬프트 연산자 이용해서 1 2 4 8 더하도록 하기
		if (Gear[i][TopIdx[i]])
			Result += (1 << i);
	}
	cout << Result;

	return 0;
}