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
	vector<int> D(n + 2);
	D[1] = 1;
	D[2] = 3;
	for (int i = 3; i < n + 1; ++i)
	{
		if (i % 2)
		{
			D[i] = D[i - 1] * 2 - 1;
			D[i] %= 10007;
		}
		else
		{
			D[i] = D[i - 1] + D[i - 2] * 2;
			D[i] %= 10007;
		}
	}

	cout << D[n];

	return 0;
}