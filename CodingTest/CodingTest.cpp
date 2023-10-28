#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;

	stack<int> Stack;

	while (K > 0)
	{
		--K;

		int a;
		cin >> a;

		// Top을 지운다.
		if (a == 0)
		{
			Stack.pop();
		}

		// Push를 한다. 
		else
		{
			Stack.push(a);
		}
	}
	
	int Sum = 0;

	// 총 합을 구한다.
	while (!Stack.empty())
	{
		Sum += Stack.top();
		Stack.pop();
	}

	cout << Sum;

	return 0;
}