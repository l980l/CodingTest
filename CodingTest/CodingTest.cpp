#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool isused[9];

void func(int count, int least)
{
	if (count == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = least; i <= N; ++i)
	{
		if (!isused[i])
		{
			arr[count] = i;
			isused[i] = true;
			func(count + 1, i);
			isused[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	func(0, 1);

	return 0;
}
