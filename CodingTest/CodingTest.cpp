#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> T(N + 1);
	vector<int> P(N + 1);

	for (int i = 1; i < N + 1; ++i)
	{
		cin >> T[i];
		cin >> P[i];
	}

	vector<long long> D(N + 1);

	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			// 현재 날짜의 상담에 영향을 주지 않는 상담일
			if (T[j] + j <= i + 1)
			{
				D[i] = max(D[i], D[j - 1] + P[j]);
			}
		}
	}

	cout << D[N];

	return 0;
}