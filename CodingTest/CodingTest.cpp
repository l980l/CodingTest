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
	vector<int> T(N + 2);
	vector<int> P(N + 2);
	for (int i = 1; i < N + 1; ++i)
	{
		cin >> T[i];
		cin >> P[i];
	}

	// i 번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익.
	vector<long long> D(N + 2);
	// 뒤쪽부터 검사하면, 이전 날짜의 상담에 영향을 받지 않을 수 있다. 
	for (int i = N; i >= 1; --i)
	{
		// 기간 안에 할 수 있는 상담인지.
		if (T[i] + i <= N + 1)
		{
			// 현재 상담이 끝나는 날짜의 최대 수익 + 현재 상담 수익과 다음날 최대 상담 수익을 비교하여 큰 값으로 세팅.
			D[i] = max(D[i + T[i]] + P[i], D[i + 1]);
		}
		else
		{
			D[i] = D[i + 1];
		}
	}

	// 근데 이걸 왜 max_element를 쓰는걸까... 그냥 D[1] 아니야? 
	//cout << *max_element(D.begin() + 1, D.end());
	cout << D[1];

	return 0;
}