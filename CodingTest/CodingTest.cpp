#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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