#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<long long> Num(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    int en = 0;
    int nowK = K;
    int nowCount = 0;
    int result = 0;

    for (int st = 0; st < N; ++st)
    {
        while (en < N)
        {
            if (Num[en] % 2)
            {
                nowK--;
                if (nowK < 0)
                {
                    nowK++;
                    break;
                }
            }
            else
                nowCount++;
            en++;
        }

        result = max(result, nowCount);

        if (Num[st] % 2)
            nowK++;
        else
            nowCount--;
    }

    cout << result;

    return 0;
}