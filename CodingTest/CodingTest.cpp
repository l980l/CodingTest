#include <iostream>
#include <stack>	

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int Result = 0;

	while (N--)
	{
		stack<char> Stack;

		string S;
		cin >> S;

		for (char c : S)
		{
			if (!Stack.empty() && Stack.top() == c)
				Stack.pop();

			else
				Stack.push(c);
		}

		if (Stack.empty())
			Result++;
	}

	cout << Result;

	return 0;
}