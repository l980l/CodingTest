#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	vector<long long> D(101);
	D[1] = 1;
	D[2] = 1;
	D[3] = 1;
	D[4] = 2;
	D[5] = 2;
	for (int i = 6; i < 101; ++i)
	{
		D[i] = D[i - 1] + D[i - 5];
	}
	while (T--)
	{
		int N;
		cin >> N;
		cout << D[N] << '\n';
	}

	return 0;
}