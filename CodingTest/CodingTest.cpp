#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	long long Sum = 0;

	stack<long long> Building;
	Building.push(1000000001);
	int Step = 0;

	while (N--)
	{
		long long Height;
		cin >> Height;

		while (Building.top() <= Height)
		{
			Building.pop();
			Step--;
		}

		Sum += Step;
		Building.push(Height);
		Step++;
	}
	Building.size();
	cout << Sum;

	return 0;
}
