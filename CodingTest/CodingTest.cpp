#include <iostream>

using namespace std;

int n, m;
int arr[10];

void func(int k)
{
	// 꽉 찬것
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int StartInt = 1;
	if (k != 0)
		StartInt = arr[k - 1];

	for (int i = StartInt; i <= n; ++i)
	{
		arr[k] = i;
		func(k+1);
		arr[k] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}
