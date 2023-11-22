#include <iostream>

using namespace std;

int N, S;
int arr[20];
int result = 0;

void func(int curIdx, int sum);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	
	func(0, 0);
	
	// S가 0인 경우에는 부분 수열이 공집합인 경우를 제외해야 하기 때문에 -1을 해준다. 
	if (S == 0)
		result--;

	cout << result;

	return 0;
}

void func(int curIdx, int sum)
{
	if (curIdx == N)
	{
		if (sum == S)
			result++;
		return;
	}
	// 현재 값을 더하지 않는 경우
	func(curIdx + 1, sum);
	// 현재 값을 더한 경우
	func(curIdx + 1, sum + arr[curIdx]);
}
