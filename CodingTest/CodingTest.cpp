#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

static int PowNum = 0;
static vector<long long> IndexTree;
static vector<long long> vecResult;

// 주어진 인덱스의 값을 Num로 변경하는 함수.
void ChangeNumber(int iIndex, long long Num)
{
	int Idx = iIndex;
	long long Diff = Num - IndexTree[Idx];

	while (Idx > 0)
	{
		IndexTree[Idx] += Diff;
		Idx /= 2;
	}
}

// StartIndex부터 EndIndex의 합을 구하는 함수
void GetSum(int StartIndex, int EndIndex)
{
	long long Sum = 0;

	int StartIdx = StartIndex;
	int EndIdx = EndIndex;

	// StartIdx가 EndIdx보다 커질 때까지 지속.
	while (StartIdx <= EndIdx)
	{
		if (StartIdx % 2 == 1)
		{
			Sum += IndexTree[StartIdx];
			++StartIdx;
		}

		if (EndIdx % 2 == 0)
		{
			Sum += IndexTree[EndIdx];
			--EndIdx;
		}

		StartIdx = StartIdx / 2;
		EndIdx = EndIdx / 2;
	}

	vecResult.push_back(Sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// N은 수의 개수, M은 수 변경 횟수, K는 구간의 합.
	int N, M, K;
	cin >> N >> M >> K;

	// IndexTree의 크기를 맞춰줘야 함.
	// 2의 PowNum 승이 N보다 같거나 커질 때의 값을 구해야 함.
	while (pow(2, PowNum) < N)
	{
		++PowNum;
	}

	// IndexTree의 크기는 2의 PowNum + 1 승으로 하면 됨. 
	IndexTree = vector<long long>(pow(2, PowNum + 1), 0);

	// 입력된 값은 리프 노드에 넣어주면 됨. 
	for (int i = 0; i < N; ++i)
	{
		long long Input = 0;
		cin >> Input;
		IndexTree[i + pow(2, PowNum)] = Input;
	}

	// IndexTree의 앞 부분 채우기. Index 1이 루트 노드이기 때문에 0까지만 사용함. 
	for (int i = IndexTree.size() - 1; i > 1; --i)
	{
		IndexTree[i / 2] += IndexTree[i];
	}

	// 이번엔 수의 변경 및 수의 합 출력 명령을 받고 처리한다. 
	for (int i = 0; i < M + K; ++i)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		// 수의 변경
		if (a == 1)
		{
			// 1 ~ N의 수로 들어오는 b를 0 ~ N-1로 매핑하기 위해 -1을 해줌. 그리고, 2의 PowNum 승에 더해줌.
			ChangeNumber(pow(2, PowNum) + b - 1, c);
		}

		// 수의 합 출력
		else if (a == 2)
		{
			GetSum(pow(2, PowNum) + b - 1, pow(2, PowNum) + c - 1);
		}
	}

	for (long long i : vecResult)
	{
		cout << i << '\n';
	}

	return 0;
}