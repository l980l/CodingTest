#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string A;
	string B;
	cin >> A >> B;

	// D[i][j]는 A의 i-1번째 글자와 B의 j-1번째 글자까지의 최장 공통 부분 수열의 길이이다.
	vector<vector<int>> D(A.size() + 1, vector<int>(B.size() + 1));

	int ASize = A.size();
	int BSize = B.size();

	for (int i = 1; i <= ASize; ++i)
	{
		for (int j = 1; j <= BSize; ++j)
		{
			// 이번에 비교할 수들이 같다면, A와 B 모두의 이전 인덱스까지의 최장 공통 부분 수열의 길이 + 1을 해야 한다.
			if (A[i - 1] == B[j - 1])
				D[i][j] = D[i - 1][j - 1] + 1;
			// 다른 경우에는 A나 B 둘 중 하나의 이전 인덱스까지의 최장 공통 부분 수열의 길이를 그대로 이어야 한다. 
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
		}
	}

	cout << D[ASize][BSize];

	return 0;
}