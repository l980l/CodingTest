#include <iostream>

using namespace std;

// true면 상근이 false면 창영이.
bool MyArr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	// 음... 1이 남으면 상근이가 이기고, 1 + 1 혹은 1 + 3이면 이김. 
	MyArr[1] = true;
	for (int i = 1; i <= 997; ++i)
	{
		if (!MyArr[i])
		{
			MyArr[i + 1] = true;
			MyArr[i + 3] = true;
		}
	}

	if (!MyArr[998])
		MyArr[999] = true;

	if (!MyArr[999])
		MyArr[1000] = true;

	if (MyArr[N])
		cout << "SK";
	else
		cout << "CY";

	return 0;
}