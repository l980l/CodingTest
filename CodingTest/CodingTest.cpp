#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	vector<string> S(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> S[i];
	}

	// 음... 각 테스트 케이스에 대해 list 만들어서 비밀번호 도출.
	for (int i = 0; i < n; ++i)
	{
		list<char> TestCase;
		auto iter = TestCase.end();	// 커서 위치.

		for (char C : S[i])
		{
			if (C == '<')
			{
				if (iter != TestCase.begin())
					--iter;
			}

			else if (C == '>')
			{
				if (iter != TestCase.end())
					++iter;
			}

			else if (C == '-')
			{
				if (iter != TestCase.begin())
					iter = TestCase.erase(--iter);
			}

			else
			{
				TestCase.insert(iter, C);
			}
		}

		for (char C : TestCase)
			cout << C;

		cout << '\n';
	}

	return 0;
}