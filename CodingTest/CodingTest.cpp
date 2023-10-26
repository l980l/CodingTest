#include <iostream>
#include <string>

using namespace std;

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

	int A, B, C;
	cin >> A >> B >> C;

	int Num = A * B * C;

	string S = to_string(Num);

	int Result[10] = {};

	for (char a : S)
	{
		++Result[a - '0'];
	}

	for (int i : Result)
	{
		cout << i << '\n';
	}

	return 0;
}