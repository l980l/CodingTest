#include <iostream>
#include <algorithm>

using namespace std;

int K;
int Num[13];
int Arr[13];

void func(int k, int st)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; ++i)
        {
            cout << Arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = st; i < K; ++i)
    {
        Arr[k] = Num[i];
        func(k + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> K;

        if (K == 0)
            return 0;

        for (int i = 0; i < K; ++i)
        {
            cin >> Num[i];
        }

        func(0, 0);
        cout << "\n";
    }

	return 0;
}
