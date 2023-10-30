#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	deque<int> Deque;

	while (N--)
	{
		string S;
		cin >> S;

		if (S == "push_front")
		{
			int a;
			cin >> a;

			Deque.push_front(a);
		}

		else if (S == "push_back")
		{
			int a;
			cin >> a;

			Deque.push_back(a);
		}

		else if (S == "pop_front")
		{
			if (Deque.empty())
				cout << -1 << "\n";
			else
			{
				cout << Deque.front() << "\n";
				Deque.pop_front();
			}
		}

		else if (S == "pop_back")
		{
			if (Deque.empty())
				cout << -1 << "\n";
			else
			{
				cout << Deque.back() << "\n";
				Deque.pop_back();
			}
		}

		else if (S == "size")
		{
			cout << Deque.size() << "\n";
		}

		else if (S == "empty")
		{
			if (Deque.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}

		else if (S == "front")
		{
			if (Deque.empty())
				cout << -1 << "\n";
			else
				cout << Deque.front() << "\n";
		}

		else if (S == "back")
		{
			if (Deque.empty())
				cout << -1 << "\n";
			else
				cout << Deque.back() << "\n";
		}
	}

	return 0;
}
