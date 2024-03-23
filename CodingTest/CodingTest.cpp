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
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> A;
		vector<int> B;
		for (int i = 0; i < N; ++i)
		{
			int temp;
			cin >> temp;
			A.push_back(temp);
		}
		for (int i = 0; i < M; ++i)
		{
			int temp;
			cin >> temp;
			B.push_back(temp);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end(), greater<int>());
		int Result = 0;
		for (int a : A)
		{
			for (int i = 0; i < M; ++i)
			{
				int NowB = B[i];
				if (a > NowB)
				{
					Result += M - i;
					break;
				}
			}
		}
		cout << Result << '\n';
	}
	return 0;
}