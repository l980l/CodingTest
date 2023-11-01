#include <iostream>
#include <stack>	

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> Stack;

	string S;
	cin >> S;

	int Step = 0;
	int Result = 0;

	for (char c : S)
	{
		if (c == '(')
		{
			// 일단 쇠 막대기의 시작이라고 생각을 해.
			Step++;
			Stack.push('(');
		}

		else
		{
			// 막대기의 끝인것.
			if (!Stack.empty() && Stack.top() == c)
			{
				Step--;
				Result++;
				Stack.push(')');
			}

			// 레이저인것.
			else if (!Stack.empty() && Stack.top() != c)
			{
				Step--;
				Result += Step;
				Stack.push(')');
			}
		}
	}

	cout << Result;

	return 0;
}