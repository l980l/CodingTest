#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	vector<int> Num(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> Num[i];
	}
	vector<long long> DP(N + 1);
	DP[1] = Num[1];
	for (int i = 2; i <= N; ++i)
	{
		DP[i] = DP[i - 1] + Num[i];
	}

	while (M--)
	{
		int i, j;
		cin >> i >> j;
		cout << DP[j] - DP[i - 1] << '\n';
	}

	return 0;
}