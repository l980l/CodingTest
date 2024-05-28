#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> Flowers;
	for (int i = 0; i < N; ++i)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;

		Flowers.push_back(make_pair(sm * 100 + sd, em * 100 + ed));
	}
	
	int Day = 301;
	int Result = 0;
	while (Day < 1201)
	{
		int NextDay = Day;	// 꽃의 추가로 변경될 종료일.
		for (int i = 0; i < N; ++i)
		{
			// 추가할 수 있는 꽃인 경우
			if (Flowers[i].first <= Day && Flowers[i].second > NextDay)
				NextDay = Flowers[i].second;
		}

		// 추가할 꽃이 없는 경우. 
		if (NextDay == Day)
		{
			cout << 0;
			return 0;
		}
		
		// 꽃 개수와 종료일 업데이트.
		Result++;
		Day = NextDay;
	}

	return 0;
}