#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x;
	cin >> n;

	vector<int> Numbers;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		Numbers.push_back(a);
	}

	cin >> x;

	sort(Numbers.begin(), Numbers.end());

	int Result = 0;

	// 음 퀵 소트처럼 탐색 대상을 절반씩 줄여나가서 nlogn이 되도록 해보자. 
	for (int i = 0; i < n - 1; ++i)
	{
		int Head = i + 1;
		int Tail = n - 1;
		int Pivot = (Head + Tail) / 2;

		while (Head <= Tail)
		{
			int Sum = Numbers[i] + Numbers[Pivot];

			if (Sum == x)
			{
				++Result;
				break;
			}

			else if (Sum > x)
			{
				Tail = Pivot - 1;
				Pivot = (Head + Tail) / 2;
			}

			else if (Sum < x)
			{
				Head = Pivot + 1;
				Pivot = (Head + Tail) / 2;
			}
		}
	}

	cout << Result;

	return 0;
}