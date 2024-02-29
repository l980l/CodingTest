#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int Num[8];
int Arr[8];
bool isused[8];

// LastIdx: 수열 끝 원소의 Num 인덱스
void func(int k, int LastIdx)
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
    
    int temp = 0;
    for (int i = LastIdx; i < N; ++i)
    {
        if (!isused[i] && temp != Num[i])
        {
            temp = Num[i];
            isused[i] = true;
            Arr[k] = Num[i];
            func(k + 1, i);
            isused[i] = false;
        }
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
    func(0, 0);

	return 0;
}
