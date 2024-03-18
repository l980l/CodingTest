#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Num;
vector<int> OPRT(4);
vector<int> vecOPRT;
long long Min = 1000000001;
long long Max = -1000000001;

// 0은 + 1은 - 2는 곱셈 3은 나눗셈. 연산을 하는 함수.
void func()
{
	long long temp = Num[0];
	for (int i = 0; i < N - 1; ++i)
	{
		switch (vecOPRT[i])
		{
		case 0:
			temp += Num[i + 1];
			break;
		case 1:
			temp -= Num[i + 1];
			break;
		case 2:
			temp *= Num[i + 1];
			break;
		case 3:
			temp /= Num[i + 1];
			break;
		}
	}
	Min = min(Min, temp);
	Max = max(Max, temp);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	Num = vector<int>(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Num[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		cin >> OPRT[i];
	}
	// 0은 + 1은 - 2는 곱셈 3은 나눗셈
	vecOPRT = vector<int>(N - 1);
	auto iter = vecOPRT.begin();
	for (int i = 0; i < 4; ++i)
	{
		fill(iter, iter + OPRT[i], i);
		iter += OPRT[i];
	}

	do
	{
		func();
	} while (next_permutation(vecOPRT.begin(), vecOPRT.end()));

	cout << Max << '\n' << Min;

	return 0;
}