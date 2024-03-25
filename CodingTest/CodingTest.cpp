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
	vector<vector<int>> Tree(N, vector<int>(N));
	vector<vector<int>> D(N,vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> Tree[i][j];
		}
	}
	D[0][0] = Tree[0][0];
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int nd = D[i - 1][j];
			if (j > 0 && nd < D[i - 1][j - 1])
			{
				nd = D[i - 1][j - 1];
			}
			D[i][j] = Tree[i][j] + nd;
		}
	}

	cout << *max_element(D[N - 1].begin(), D[N - 1].end());

	return 0;
}