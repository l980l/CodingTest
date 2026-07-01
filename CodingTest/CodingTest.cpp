#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M;
    cin >> T;

    for (int tcn = 1; tcn <= T; ++tcn)
    {
        cin >> N >> M;
        vector<int> A(N);
        vector<int> B(M);

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        for (int i = 0; i < M; ++i)
        {
            cin >> B[i];
        }

        if (N > M)
        {
            swap(N, M);
            swap(A, B);
        }

        int mx = 0;
        for (int i = 0; i < M - (N - 1); ++i)
        {
            int sum = 0;
            for (int j = 0; j < N; ++j)
            {
                sum += A[j] * B[i + j];
            }

            mx = max(mx, sum);
        }

        cout << '#' << tcn << ' ' << mx << '\n';
    }

    return 0;
}