#include <iostream>

using namespace std;

int n;
int s[8], w[8];
int mx = 0;
int cnt = 0; // 깨져있는 계란 수

// a번째 계란으로 다른걸 깰 차례
void solve(int a)
{
	// a가 끝 인덱스를 넘어간 경우
	if (a == n)
	{
		if (mx < cnt)
			mx = cnt;
		return;
	}
	// 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없는 경우
	if (s[a] <= 0 || cnt == n - 1)
	{
		solve(a + 1);
		return;
	}

	for (int t = 0; t < n; ++t)
	{
		// 들고 있는 계란이거나, 이미 깨진 달걀이면 continue
		if (t == a || s[t] <= 0)
			continue;
		// 내구도 깎기
		s[a] -= w[t];
		s[t] -= w[a];
		// 깨진 달걀 수 올리기
		if (s[a] <= 0)
			cnt++;
		if (s[t] <= 0)
			cnt++;
		solve(a + 1);
		// 깨진 달걀 수 원상 복귀
		if (s[a] <= 0)
			cnt--;
		if (s[t] <= 0)
			cnt--;
		// 내구도 원상 복구
		s[a] += w[t];
		s[t] += w[a];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i] >> w[i];
	}

	solve(0);
	cout << mx;

	return 0;
}