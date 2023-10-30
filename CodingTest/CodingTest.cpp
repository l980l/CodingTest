#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	
	int Sum = 0;

	// 덱에 1~N 넣기.
	deque<int> Deque;
	for (int i = 1; i <= N; ++i)
	{
		Deque.push_back(i);
	}

	while (M--)
	{
		int a;
		cin >> a;

		int Idx = 0;
		while (!Deque.empty())
		{
			if (Deque.at(Idx) == a)
			{
				Sum += Idx;

				// 맨 앞으로 옮기고
				while (Idx--)
				{
					Deque.push_back(Deque.front());
					Deque.pop_front();
				}

				// 맨 앞 팝.
				Deque.pop_front();
				break;
			}

			else if (Deque.at(Deque.size() - 1 - Idx) == a)
			{
				++Idx;
				Sum += Idx;

				// 맨 앞으로 옮기고
				while (Idx--)
				{
					Deque.push_front(Deque.back());
					Deque.pop_back();
				}

				// 맨 앞 팝.
				Deque.pop_front();
				break;
			}

			Idx++;
		}
	}

	cout << Sum;

	return 0;
}
