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

	// i의 최소 제곱수의 합의 항 개수
	vector<int> D(N + 1);

	for (int i = 1; i < N + 1; ++i)
	{
		// i를 구성하는 제곱수는 최대 i 개의 1제곱수임.
		D[i] = i;
		// j의 제곱이 i보다 작은 경우, j의 제곱을 뺀 수의 최소 제곱수의 합의 항 개수에 + 1(j의 제곱 1개를 더해주는 거임)만 한 값과 현재 값을 비교하여 더 작은 값으로 세팅한다. 
		for (int j = 1; j * j <= i; ++j)
		{
			D[i] = min(D[i], D[i - j * j] + 1);
		}
	}

	cout << D[N];

	return 0;
}