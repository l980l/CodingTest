#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<int> Queue;

	while (N--)
	{
		string S;
		cin >> S;

		if (S == "push")
		{
			int a;
			cin >> a;

			Queue.push(a);
		}

		else if (S == "front")
		{
			if (Queue.empty())
				cout << -1 << "\n";

			else
				cout << Queue.front() << "\n";
		}

		else if (S == "back")
		{
			if (Queue.empty())
				cout << -1 << "\n";

			else
				cout << Queue.back() << "\n";
		}

		else if (S == "pop")
		{
			if (Queue.empty())
				cout << -1 << "\n";

			else
			{
				cout << Queue.front() << "\n";
				Queue.pop();
			}
		}

		else if (S == "size")
		{
			cout << Queue.size() << "\n";
		}

		else if (S == "empty")
		{
			if (Queue.empty())
				cout << 1 << "\n";

			else
				cout << 0 << "\n";
		}
	}

	return 0;
}
