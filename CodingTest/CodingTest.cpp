#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	vector<vector<int>> D(41,vector<int>(2));
	D[0][0] = 1;
	D[0][1] = 0;
	D[1][0] = 0;
	D[1][1] = 1;
	for (int i = 2; i < 41; ++i)
	{
		D[i][0] = D[i - 1][0] + D[i - 2][0];
		D[i][1] = D[i - 1][1] + D[i - 2][1];
	}

	while (T--)
	{
		int N;
		cin >> N;
		cout << D[N][0] << ' ' << D[N][1] << '\n';
	}

	return 0;
}