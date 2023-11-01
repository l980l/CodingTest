#include <iostream>
#include <stack>	

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	long long Result = 0;
	bool bWrong = false;

	stack<long long> Stack;

	for (char c : S)
	{
		if (c == '(')
			Stack.push('(');

		else if (c == '[')
			Stack.push('[');

		else if (c == ')')
		{
			if (Stack.empty())
			{
				bWrong = true;
				break;
			}

			else if (Stack.top() == '(')
			{
				Stack.pop();

				// top이 숫자인 경우 +2를 해준다. 
				if (!Stack.empty() && Stack.top() != '(' && Stack.top() != '[' && Stack.top() != ')' && Stack.top() != ']')
				{
					// 음 이게 잘 되려나.
					long long A = Stack.top() - '0';
					A += 2;
					Stack.pop();
					char B = A + '0';
					Stack.push(B);
				}

				// Stack이 비어있다면 Result에 2 더해주기.
				else if (Stack.empty())
					Result += 2;
				
				// top이 숫자가 아니면 2를 넣어준다. 
				else
					Stack.push('2');
			}

			// top이 숫자인 경우
			else
			{
				long long Temp = 0;

				while (Stack.top() != '(')
				{
					// top이 숫자인 경우 Temp에 다 누적해서 더해준 다음 *2를 해준다. 
					if (Stack.top() != '[' && Stack.top() != ')' && Stack.top() != ']')
					{
						// 음 이게 잘 되려나.
						long long A = Stack.top() - '0';
						Temp += A;
						Stack.pop();
					}

					else
					{
						bWrong = true;
						break;
					}
				}
				
				Stack.pop();
				Temp *= 2;

				if (Stack.empty())
					Result += Temp;
				else
					Stack.push(Temp + '0');
			}
		}

		else if (c == ']')
		{
			if (Stack.empty())
			{
				bWrong = true;
				break;
			}

			else if (Stack.top() == '[')
			{
				Stack.pop();

				if (!Stack.empty() && Stack.top() != '(' && Stack.top() != '[' && Stack.top() != ')' && Stack.top() != ']')
				{
					// 음 이게 잘 되려나.
					long long A = Stack.top() - '0';
					A += 3;
					Stack.pop();
					char B = A + '0';
					Stack.push(B);
				}

				// Stack이 비어있다면 Result에 3 더해주기.
				else if (Stack.empty())
					Result += 3;

				// top이 숫자가 아니면 3를 넣어준다. 
				else
					Stack.push('3');
			}

			// top이 숫자인 경우
			else
			{
				long long Temp = 0;

				while (Stack.top() != '[')
				{
					// top이 숫자인 경우 Temp에 다 누적해서 더해준 다음 *3를 해준다. 
					if (Stack.top() != '(' && Stack.top() != '[' && Stack.top() != ')' && Stack.top() != ']')
					{
						// 음 이게 잘 되려나.
						long long A = Stack.top() - '0';
						Temp += A;
						Stack.pop();
					}

					else
					{
						bWrong = true;
						break;
					}
				}

				Stack.pop();
				Temp *= 3;

				if (Stack.empty())
					Result += Temp;
				else
					Stack.push(Temp + '0');
			}
		}
	}

	// 잘못된 괄호열인 경우
	if (bWrong)
		cout << 0;
	else
		cout << Result;

	return 0;
}