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

	// D[i][k]. 길이가 i인 계단 수 중에서 마지막 숫자가 k로 끝나는 수의 개수를 저장.
	vector<vector<long long>> D(101, vector<long long>(10));
	// 길이가 1인 계단 수는 0을 제외하고 각각 1개씩 있다.
	for (int i = 1; i < 10; ++i)
	{
		D[1][i] = 1;
	}

	// 길이가 2부터 N인 수에 대해서는 마지막 숫자가 0에서 9까지 가능하다.
	for (int i = 2; i <= N; ++i)
	{
		for (int k = 0; k < 10; ++k)
		{
			// k가 0이 아닌 경우, k-1로 끝나는 계단 수 뒤에 k를 붙여 새로운 계단 수를 만든다.
			if (k != 0)
				D[i][k] += D[i - 1][k - 1];
			// k가 9가 아닌 경우, k+1로 끝나는 계단 수 뒤에 k를 붙여 새로운 계단 수를 만든다.
			if (k != 9)
				D[i][k] += D[i - 1][k + 1];

			D[i][k] %= 1000000000;
		}
	}

	long long result = 0; 
	// 길이가 N인 모든 계단 수를 더한다.
	for (int i = 0; i <= 9; ++i)
	{
		result += D[N][i];
	}
	result %= 1000000000;
	cout << result;

	return 0;
}