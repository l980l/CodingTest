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
		int N;
		cin >> N;
		vector<int> C(N);
		// i를 만들 수 있는 방법의 수. M의 단위가 10000까지니까. M 자체로 크기를 정해도 되지만, 화폐단위를 입력 받을 때 바로 처리해야 하기 때문에 미리 크기를 정해둠.
		vector<long long> D(10001);
		for (int i = 0; i < N; ++i)
		{
			cin >> C[i];
		}
		int M;
		cin >> M;
		// 이게 중요하다. 금액이 0인 경우는 문제로 나오지도 않는데, 기반 조건을 만들기 위해 설정해야 한다. 이렇게 해야, D[화폐 단위]에 1이 더해질 것이다. 
		// 이 방법이 이해가 안된다면, 아마 모든 화폐 단위에 대해 초기 D 값을 1로 두면 될 것 같다.
		D[0] = 1;
		// 모든 코인들에 반복.
		for (int i = 0; i < N; ++i)
		{
			// 현재 코인 금액부터, 목표 금액까지.
			// D[현재 금액 j] += D[현재 금액 - 화폐 단위]
			for (int j = C[i]; j <= M; ++j)
			{
				D[j] += D[j - C[i]];
			}
		}
		cout << D[M] << '\n';
	}


	return 0;
}