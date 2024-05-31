#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N, M;
	cin >> N >> M;
	vector<long long> Num(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Num[i];
	}

	sort(Num.begin(), Num.end());

	long long Min = 2000000001;
	for (int i = 0; i < N - 1; ++i)
	{
		long long Now = Num[i];
		// Num + M이 어디 들어가나
		auto iter = lower_bound(Num.begin(), Num.end(), Now + M);
		// M 이상의 값을 구한거임.
		if (iter != Num.end())
		{
			Min = min(Min, *iter - Num[i]);
			if (Min == M)
			{
				cout << Min;
				return 0;
			}
		}
	}
	cout << Min;

	return 0;
}