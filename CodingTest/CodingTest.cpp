#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// 음 해보니까 입력된 순서를 인덱스로 해서 출력하니까 쌍으로 묶어서 저장해야 될듯?
	stack<pair<int, int>> Tower;

	int Temp;
	cin >> Temp;
	int Idx = 1;
	Tower.push(make_pair(Temp, Idx));
	cout << 0 << " ";
	N -= 1;

	while (N--)
	{
		int Temp;
		cin >> Temp;
		Idx++;

		while (!Tower.empty())
		{
			if (Tower.top().first > Temp)
			{
				cout << Tower.top().second << " ";
				Tower.push(make_pair(Temp, Idx));
				break;
			}

			else if (Tower.top().first < Temp)
			{
				Tower.pop();

				if (Tower.empty())
				{
					Tower.push(make_pair(Temp, Idx));
					cout << 0 << " ";
					break;
				}
			}
		}
	}

	return 0;
}
