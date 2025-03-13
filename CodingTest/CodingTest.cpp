#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> d(N + 1, vector<int>(N + 1, 0x3f3f3f3f));
    for (int i = 0; i <= N; ++i)
    {
        d[i][i] = 0;
    }

    int A, B, T;
    while (M--)
    {
        cin >> A >> B >> T;
        d[A][B] = min(d[A][B], T);
    }

    int K;
    cin >> K;

    vector<int> f(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> f[i];
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<int> result;
    int minSum = 0x7f7f7f7f;
    int nowMax = 0;
    int now = 0;
    for (int i = 1; i <= N; ++i)
    {
        nowMax = 0;
        for (int cur : f)
        {
            now = 0;
            now += d[cur][i];
            now += d[i][cur];
            
            nowMax = max(nowMax, now);
        }

        if (minSum == nowMax)
            result.emplace_back(i);

        else if (minSum > nowMax)
        {
            minSum = nowMax;
            result.clear();
            result.emplace_back(i);
        }
    }

    sort(result.begin(), result.end());

    for (int city : result)
        cout << city << " ";

    return 0;
}