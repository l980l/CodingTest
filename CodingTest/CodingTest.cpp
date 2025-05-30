#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M, Result;

    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<int> Coins(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> Coins[i];
        }

        cin >> M;

        vector<int> DP(M + 1, 0); // 음... 어떤 DP로 해야되지? 음... i를 표현할 수 있는 방법의 수를 저장하면 되려나? 
        DP[0] = 1;

        for (int i = 0; i < N; ++i)
        {
            for (int j = Coins[i]; j <= M; ++j)
            {
                DP[j] += DP[j - Coins[i]];
            }
        }

        cout << DP[M] << '\n';
    }

    return 0;
}
