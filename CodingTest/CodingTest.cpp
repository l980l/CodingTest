#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long C;
	cin >> N >> C;
	vector<pair<long long, int>> Num(N);
	for (int i = 0; i < N; ++i)
	{
		long long temp;
		cin >> temp;
		Num[i] = make_pair(temp, i); 
	}
	sort(Num.begin(), Num.end());

	vector<tuple<int, int, long long>> SortedNum;
	long long prev = Num[0].first;
	SortedNum.push_back(make_tuple(1, N - Num[0].second,prev)); // 2번 인자는 나중에 greater로 오름차순으로 정렬되야 하는데, 앞에서 나온걸 먼저 두고 싶기 때문에 앞에 올수록 큰수로 만듦.
	for (int i = 1; i < N; ++i)
	{
		if (Num[i].first == prev)
		{
			int x, y;
			long long ll;
			tie(x, y, ll) = SortedNum.back();
			SortedNum.back() = make_tuple(x + 1, y, ll);
		}
		else
		{
			prev = Num[i].first;
			SortedNum.push_back(make_tuple(1, N - Num[i].second, prev));
		}
	}
	// 이번엔 오름차 순으로.
	sort(SortedNum.begin(), SortedNum.end(), greater<tuple<int, int, long long>>());
	auto iter = SortedNum.begin();
	for (; iter != SortedNum.end(); ++iter)
	{
		int x, y;
		long long ll;
		tie(x, y, ll) = *iter;
		for (int i = 0; i < x; ++i)
		{
			cout << ll << ' ';
		}
	}
	return 0;
}