#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
vector<int> Num;
bool isused[10];

void func(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// 사용한적 없는 수인 경우
		if (!isused[i])
		{
			isused[i] = true;
			arr[k] = Num[i];
			func(k + 1);
			isused[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		Num.push_back(temp);
	}
	sort(Num.begin(), Num.end());

	func(0);

	return 0;
}
