#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int Distance[100002] = {};
	fill(Distance, Distance + 100001, -1);
	Distance[N] = 0;

	queue<int> Queue;
	Queue.push(N);


	while (!Queue.empty())
	{
		int Cur = Queue.front();
		Queue.pop();
		// -1, +1, *2 
		if (Cur - 1 >= 0 && Distance[Cur - 1] == -1)
		{
			Distance[Cur - 1] = Distance[Cur] + 1;
			Queue.push(Cur - 1);
		}
		if (Cur + 1 < 100001 && Distance[Cur + 1] == -1)
		{
			Distance[Cur + 1] = Distance[Cur] + 1;
			Queue.push(Cur + 1);
		}
		if (2 * Cur < 100001 && Distance[2 * Cur] == -1)
		{
			Distance[2 * Cur] = Distance[Cur] + 1;
			Queue.push(2 * Cur);
		}
	}

	cout << Distance[K];

	return 0;
}