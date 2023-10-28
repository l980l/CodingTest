#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> Stack;		
	vector<char> vecResult;
	int NextNum = 1;
	bool bPossible = true;
	int n;
	cin >> n;

	// 음... 뭔소리지 ㅋㅋ 자~ 수를 넣고~ 빼. 딱 알았다. pop하는 순서를 맞추려는거구나. 음... 언제 NO가 출력될까... 음...3개를 연달아 넣었을 때, 3 1 2 순서로 빼야 될 때 NO가 나오는거 같은데... 입력된 값이 Top보다 작고, 다음에 넣을 값보다 작으면 NO 인듯?
	// 아 --n이 아니라 n--으로 해야 되는구나. --n이면 먼저 빼고 비교하니까 먼저 0이 되니까 음~
	while (n--)
	{
		// 수 입력받고 
		int a;
		cin >> a;

		// 아직 해당 값을 스택에 안 넣은 경우.
		if (NextNum <= a)
		{
			while (NextNum <= a)
			{
				Stack.push(NextNum);
				vecResult.push_back('+');
				NextNum++;
			}
		}

		// top이 a가 아닌 경우에는 NO를 출력.
		if (Stack.top() != a)
		{
			bPossible = false;
			break;
		}

		else
		{
			Stack.pop();
			// "-"는 안되는데 '-'는 되네. 이 둘의 차이를 잘 몰라서 자꾸 걸리네. 생각해보니까 " "는 문자열고 ' '는 문자를 감싸는거 같긴한데... 흠...
			vecResult.push_back('-');
		}
	}

	// 답을 저장했다가 bPossible이 false면 그냥 NO 출력. 
	if (bPossible)
	{
		for (char a : vecResult)
		{
			cout << a << "\n";
		}
	}

	else
		cout << "NO";

	return 0;
}