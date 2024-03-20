#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> Nums;
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		int size = (int)temp.size();
		reverse(temp.begin(), temp.end());
		// stoll는 string을 long long으로 바꿔주는 함수인데, string 헤더를 include 해야 사용할 수 있음. 
		Nums.push_back(stoll(temp));
	}
	sort(Nums.begin(), Nums.end());
	for (long long i : Nums)
	{
		cout << i <<'\n';
	}

	return 0;
}