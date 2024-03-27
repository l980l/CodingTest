#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> Num(n + 1);
	for (int i = 1; i < n + 1; ++i)
	{
		cin >> Num[i];
	}

	vector<int> D(n + 1);
	for (int i = 1; i < n + 1; ++i)
	{
		D[i] = max(0, D[i - 1]) + Num[i];
	}

	cout << *max_element(D.begin() + 1, D.end());

	return 0;
}