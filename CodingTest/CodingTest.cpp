#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		vector<int> Stock(N);
		for (int i = 0; i < N; ++i)
			cin >> Stock[i];
		// 뒤에서부터 주식 값을 확인하며 판매.
		int Max = Stock[N - 1];	// 판매 전까지 가장 큰 주식 값.
		long long Result = 0;
		for (int i = N - 2; i >= 0; --i)
		{
			// 이날 가격이 이후의 가격보다 큰 경우. Max를 업데이트. 그 전에 다 팔아야 되는 것이지.
			if (Stock[i] > Max)
				Max = Stock[i];
			// 지금까지 가장 큰 주식 가격 - 현재 주식 가격을 구하고 누적.
			Result += Max - Stock[i];
		}
		cout << Result << '\n';
	}

	return 0;
}