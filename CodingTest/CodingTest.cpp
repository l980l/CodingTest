#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int Num[8];
int Arr[8];
bool isused[8];

void func(int k)
{
    if (k == M)
    {
        for (int i = 0;i<M;++i)
        {
            cout << Arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int Temp = 0;   // 이전에 Arr에 추가한 수를 임시 저장하고, 이것과 같은 값을 추가하게 된다면 중복 수열이다. 
    for (int i = 0; i < N; ++i)
    {
        if (!isused[i] && Temp != Num[i])
        {
            Temp = Num[i];
            Arr[k] = Num[i];
            isused[i] = true;
            func(k + 1);
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
    func(0);

    return 0;
}