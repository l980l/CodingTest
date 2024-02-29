#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int Num[7];
int Arr[7];

void func(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << Arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (i > 0 && Num[i] == Num[i - 1])
            continue;
        Arr[k] = Num[i];
        func(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }
    sort(Num, Num + N);
    func(0);

	return 0;
}
