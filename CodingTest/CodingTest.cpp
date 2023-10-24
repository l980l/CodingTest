#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SecondSort(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, X;
	cin >> N >> X;
	
	vector<pair<int, int>> MyVector;

	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;

		MyVector.push_back(make_pair(a, i));
	}

	sort(MyVector.begin(), MyVector.end());

	int EndIdx = 0;

	for (int i = 0; i < N; ++i)
	{
		// 처음으로 X 이상인게 나오면 i - 1까지만 출력하면 됨.
		if (MyVector[i].first >= X)
		{
			EndIdx = i;
			break;
		}
	}

	// 입력 받은 순서로 다시 정렬
	sort(MyVector.begin(), MyVector.begin() + EndIdx, SecondSort);

	for (int i = 0; i < EndIdx; ++i)
	{
		cout << MyVector[i].first << ' ';
	}

	return 0;
}