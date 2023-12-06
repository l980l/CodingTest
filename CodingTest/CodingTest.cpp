#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int Num[10];

void func(int k, int StartIdx)
{
	if (k == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = StartIdx; i < N; ++i)
	{
		arr[k] = Num[i];
		func(k + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> Num[i];
	}
	sort(Num, Num + N);
	func(0, 0);

	return 0;
}
