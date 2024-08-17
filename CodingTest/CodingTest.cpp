#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// N이 1이면 0 바로 반환.
	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	// 에라스토테네스의 체
	vector<bool> vecIsPrime(N + 1, true);
	vector<int> vecPrime;

	vecIsPrime[2] = true;

	for (int i = 2; i * i <= N; ++i)
	{
		if (vecIsPrime[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				vecIsPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		if (vecIsPrime[i])
			vecPrime.push_back(i);
	}

	int st = 0;
	int en = 0;

	int count = 0;
	int sum = 0;

	sum += vecPrime[en];

	while (st <= en && en < vecPrime.size())
	{
		if (sum == N)
		{
			count++;
			st++;
			en++;

			if (en < vecPrime.size())
				sum = sum - vecPrime[st - 1] + vecPrime[en];
		}

		else if (sum < N)
		{
			en ++;

			if(en < vecPrime.size())
				sum += vecPrime[en];
		}

		else if (sum > N)
		{
			st++;

			if (st <= en)
				sum -= vecPrime[st - 1];
		}
	}

	cout << count;

	return 0;		
}