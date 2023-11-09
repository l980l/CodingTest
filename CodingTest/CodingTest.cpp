#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int Dist[100003];
queue<int> Queue;

void teleport(int S)
{
	if (S == 0)
		return;
	int temp = S;

	temp <<= 1;
	while (temp - 1 <= K)
	{
		if (Dist[temp] == -1)
		{
			Dist[temp] = Dist[S];
			Queue.push(temp);
			if (temp == K)
				return;
		}
		temp <<= 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	fill(Dist, Dist + 100003, -1);
	Dist[N] = 0;
	Queue.push(N);
	teleport(N);
	while (!Queue.empty())
	{
		int Cur = Queue.front();
		Queue.pop();

		if (Cur == K)
		{
			cout << Dist[Cur];
			return 0;
		}

		if (Cur - 1 >= 0 && Dist[Cur - 1] == -1)
		{
			Dist[Cur - 1] = Dist[Cur] + 1;
			Queue.push(Cur - 1);
			teleport(Cur - 1);
		}

		if (Cur + 1 <= 100001 && Dist[Cur + 1] == -1)
		{
			Dist[Cur + 1] = Dist[Cur] + 1;
			Queue.push(Cur + 1);
			teleport(Cur + 1);
		}
	}

	return 0;
}