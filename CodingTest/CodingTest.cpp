#include <iostream>
#include <list>

using namespace std;

void DeleteK(int K);

static list<int> MyList;
static list<int>::iterator iter;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	// 초기 세팅
	for (int i = 1; i <= N; ++i)
	{
		MyList.push_back(i);
	}
	iter = MyList.begin();

	cout << "<";

	while (true)
	{
		DeleteK(K);

		if (MyList.empty())
		{
			cout << ">";
			break;
		}

		else
			cout << ", ";
	}

	return 0;
}

void DeleteK(int K)
{
	// 음... K가 1부터 N번째로 값이 들어오는데 iter는 처음부터 1번째니까, 1 이상까지만 더해줘야 할듯.
	while (K > 1)
	{
		--K;
		++iter;

		// 맨 뒤로 갔으면 다시 맨 앞으로 이동.
		if (iter == MyList.end())
			iter = MyList.begin();
	}

	cout << *iter;
	iter = MyList.erase(iter);

	// 맨 뒤로 갔으면 다시 맨 앞으로 이동.
	if (iter == MyList.end())
		iter = MyList.begin();
}