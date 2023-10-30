#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string S = "";
		cin >> S;

		int n;
		cin >> n;

		// '[' 받고 버림
		char temp;
		cin >> temp;

		// Deque에 원소 넣기
		deque<int> Deque(n);
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			Deque[i] = a;

			// ']'나 ',' 받고 버림
			cin >> temp;
		}

		// n이 0일때
		if(!n)
			cin >> temp;

		bool bFront = true;
		bool bError = false;

		// 명령 수행.
		for (char c : S)
		{
			// 뒤집기
			if (c == 'R')
			{
				if (bFront)
					bFront = false;
				else
					bFront = true;
			}

			// 버리기
			else if (c == 'D')
			{
				if (Deque.empty())
				{
					cout << "error" << "\n";
					bError = true;
					break;
				}

				else
				{
					// pop_front
					if (bFront)
						Deque.pop_front();
					
					// pop_back
					else
						Deque.pop_back();
				}
			}
		}

		if (!bError)
		{
			cout << "[";
			for (int i = 0; i < Deque.size(); ++i)
			{
				if(bFront)
					cout << Deque[i];
				else
					cout << Deque[Deque.size() - 1 - i];

				if (i != Deque.size() - 1)
					cout << ",";
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}
