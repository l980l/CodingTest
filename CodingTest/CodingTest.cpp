#include <iostream>	

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 음... 문제가 스택을 구현라고 했으니까 STL 쓰지 말고 직접 구현해야겠지? 음... 그냥 배열로 구현하면 되겠지?
	int ArrStack[10000];	// 명령이 최대 10000개라서 스택도 최대 10000개임.
	int Top = -1;			// 꼭대기. 전부 비어있다면 -1.

	// 명령어 개수
	int N;
	cin >> N;

	while (N > 0)
	{
		--N;

		string S;
		cin >> S;

		if (S == "push")
		{
			int X;
			cin >> X;

			ArrStack[Top + 1] = X;
			Top++;
		}

		else if (S == "pop")
		{
			// 비어있지 않다면
			if (Top != -1)
			{
				cout << ArrStack[Top] << "\n";
				Top--;
			}

			// 비어있다면
			else
				cout << -1 << "\n";
		}

		else if (S == "size")
		{
			cout << Top + 1 << "\n";
		}

		else if (S == "empty")
		{
			if (Top == -1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}

		else if (S == "top")
		{
			// 비어있지 않다면
			if (Top != -1)
			{
				cout << ArrStack[Top] << "\n";
			}

			// 비어있다면
			else
				cout << -1 << "\n";
		}
	}

	return 0;
}