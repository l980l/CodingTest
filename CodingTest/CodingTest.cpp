#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> DP(n + 1);
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= n; ++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
		DP[i] %= 10007;
	}

	cout << DP[n];

	return 0;
}